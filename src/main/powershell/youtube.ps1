#!/bin/pwsh
# Dependencies:
# 	mpv, youtube-dl
# It is recommended that you modify your mpv.conf to limit the max fps and
# quality of videos as to not overburden your internet connection / CPU
# please add this line to your mpvc:
# ytdl-format=bestvideo[height<=?1080][fps<=?30][vcodec!=?vp9]+bestaudio/best
# A valid google api key is also required
#
# Define your google api key here
$env:GoogleApiKey = "AIzaSyARpjRn7-t39LyzGTSgoiPZcU8QVA7fi0I"

# Search Youtube and return video url
function global:syt {
	param (
		[Parameter(Mandatory = $true, Position = 0)]
		[string] $query
	)
	$query = $query -replace '\s+', '+'
	$searchUri = "https://www.googleapis.com/youtube/v3/search?q=$query&key=$env:GoogleApiKey&maxResults=20&part=snippet&type=video"
	$response = Invoke-RestMethod -Uri $searchUri -Method Get
	# Creates table of result number, video title, and channel
	$tbl = New-Object System.Data.DataTable "Search Results"
	$col0 = New-Object System.Data.DataColumn Result
	$col1 = New-Object System.Data.DataColumn Title
	$col2 = New-Object System.Data.DataColumn Channel
	$tbl.columns.add($col0)
	$tbl.columns.add($col1)
	$tbl.columns.add($col2)
	for ( $i = 1; $i -le $response.items.count; $i++ ) {
		$row = $tbl.NewRow()
		$row.Result = $i
		$row.Title = [System.Net.WebUtility]::HtmlDecode($response.items[$i - 1].snippet.title)
		$row.Channel = [System.Net.WebUtility]::HtmlDecode($response.items[$i - 1].snippet.channeltitle)
		$tbl.rows.add($row)
	}
	$tbl | Format-Table | Out-Host
	# Loops through number until input is correct
	do {
		try {
			$isNum = $true
			$Selection = Read-Host "Selection #"
			if ($Selection) {
				[int]$Selection = $Selection
			}
			else {
				return ""
			}
		}
		catch {
			$isNum = $false
		}
	} until ($Selection -ge 1 -and $Selection -le $response.items.count -and $isNum)
	return "https://youtube.com/watch?v=$($response.items[$selection - 1].id.videoId)"
}

# Watch youtube videos over command line
function global:yt {
	$search = ""
	do {
		$query = Read-Host "Search for a video"
		if ($query) {
			$search = $query
		}
		if ($search -and !($search.equals("exit"))) {
			$selection = $(syt $search)
			if ($selection) {
				mpv $selection --no-terminal
			}
		}
	} until ($search.equals("exit"))
}
yt
