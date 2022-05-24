/* //!/bin/env pwsh */
/* param ( */
/* 	$option */
/* ) */
/* // Define your google api key here */
/* $env:GoogleApiKey = "AIzaSyAr9WbWmgDQ4EkMBS4AsWj9ikkKODNZs78" */

/* // Search Youtube and return video url */
/* function global:syt { */
/* 	param ( */
/* 		[Parameter(Mandatory = $true, Position = 0)] */
/* 		[string] $query */
/* 	) */
/* 	$query = $query -replace '\s+', '+' */
/* 	$searchUri = "https://www.googleapis.com/youtube/v3/search?q=$query&key=$env:GoogleApiKey&maxResults=20&part=snippet&type=video" */
/* 	$response = Invoke-RestMethod -Uri $searchUri -Method Get */
/* 	# Creates table of result number, video title, and channel */
/* 	$tbl = New-Object System.Data.DataTable "Search Results" */
/* 	$col0 = New-Object System.Data.DataColumn Result */
/* 	$col1 = New-Object System.Data.DataColumn Title */
/* 	$col2 = New-Object System.Data.DataColumn Channel */
/* 	$tbl.columns.add($col0) */
/* 	$tbl.columns.add($col1) */
/* 	$tbl.columns.add($col2) */
/* 	for ( $i = 1; $i -le $response.items.count; $i++ ) { */
/* 		$row = $tbl.NewRow() */
/* 		$row.Result = $i */
/* 		$row.Title = [System.Net.WebUtility]::HtmlDecode($response.items[$i - 1].snippet.title) */
/* 		$row.Channel = [System.Net.WebUtility]::HtmlDecode($response.items[$i - 1].snippet.channeltitle) */
/* 		$tbl.rows.add($row) */
/* 	} */
/* 	$tbl | Format-Table | Out-Host */
/* 	# Loops through number until input is correct */
/* 	do { */
/* 		try { */
/* 			$isNum = $true */
/* 			$Selection = Read-Host "Selection #" */
/* 			if ($Selection) { */
/* 				[int]$Selection = $Selection */
/* 			} */
/* 			else { */
/* 				return "" */
/* 			} */
/* 		} */
/* 		catch { */
/* 			$isNum = $false */
/* 		} */
/* 	} until ($Selection -ge 1 -and $Selection -le $response.items.count -and $isNum) */
/* 	return "https://youtube.com/watch?v=$($response.items[$selection - 1].id.videoId)" */
/* } */

/* function global:syp { */
/* 	param ( */
/* 		[Parameter(Mandatory = $true, Position = 0)] */
/* 		[string] $query */
/* 	) */
/* 	$query = $query -replace '\s+', '+' */
/* 	$searchUri = "https://www.googleapis.com/youtube/v3/search?q=$query&key=$env:GoogleApiKey&maxResults=5&part=snippet&type=playlist" */
/* 	$response = Invoke-RestMethod -Uri $searchUri -Method Get */
/* 	# Creates table of result number, video title, and channel */
/* 	$tbl = New-Object System.Data.DataTable "Search Results" */
/* 	$col0 = New-Object System.Data.DataColumn Result */
/* 	$col1 = New-Object System.Data.DataColumn Title */
/* 	$tbl.columns.add($col0) */
/* 	$tbl.columns.add($col1) */
/* 	for ( $i = 1; $i -le $response.items.count; $i++ ) { */
/* 		$row = $tbl.NewRow() */
/* 		$row.Result = $i */
/* 		$row.Title = [System.Net.WebUtility]::HtmlDecode($response.items[$i - 1].snippet.title) */
/* 		$tbl.rows.add($row) */
/* 	} */
/* 	$tbl | Format-Table | Out-Host */
/* 	# Loops through number until input is correct */
/* 	do { */
/* 		try { */
/* 			$isNum = $true */
/* 			$Selection = Read-Host "Selection #" */
/* 			if ($Selection) { */
/* 				[int]$Selection = $Selection */
/* 			} */
/* 			else { */
/* 				return "" */
/* 			} */
/* 		} */
/* 		catch { */
/* 			$isNum = $false */
/* 		} */
/* 	} until ($Selection -ge 1 -and $Selection -le $response.items.count -and $isNum) */
/* 	return "https://youtube.com/playlist?list=$($response.items[$selection - 1].id.playlistId)" */
/* } */

/* // Download music from youtube to music directory */
/* function global:yaudio { */
/* 	param ( */
/* 		[string] $url, */
/* 		[string] $playlist */
/* 	) */
/* 	if ($url) { */
/* 		yt-dlp $url -i --restrict-filenames --extract-audio --audio-format mp3 --audio-quality 0 -o $HOME/Music/$playlist/"%(title)s.(ext)s" */
/* 	} */
/* } */

/* // Download youtube url to videos directory */
/* function global:yvideo { */
/* 	param ( */
/* 		[string] $url, */
/* 		[string] $playlist */
/* 	) */
/* 	if ($url) { */
/* 		yt-dlp $url --restrict-filenames -o "$HOME/Videos/$playlist/%(title)s.%(ext)s" --all-subs -f "bv[height<=?1080][fps<=?30]+ba" */
/* 	} */
/* } */

/* function global:da { */
/* 	param ( */
/* 		[Parameter(Mandatory = $true, Position = 0)] */
/* 		[string] $query */
/* 		) */
/* 	yaudio $(syt $query) */
/* } */

/* function global:dv { */
/* 	param ( */
/* 		[Parameter(Mandatory = $true, Position = 0)] */
/* 		[string] $query */
/* 		) */
/* 	yvideo $(syt $query) */
/* } */

/* function global:dap { */
/* 	param ( */
/* 		[Parameter(Mandatory = $true, Position = 0)] */
/* 		[string] $query, */
/* 		[Parameter(Mandatory = $true, Position = 1)] */
/* 		[string] $folder */
/* 		) */
/* 	yaudio $(syp $query) $folder */
/* } */

/* function global:dvp { */
/* 	param ( */
/* 		[Parameter(Mandatory = $true, Position = 0)] */
/* 		[string] $query, */
/* 		[Parameter(Mandatory = $true, Position = 1)] */
/* 		[string] $folder */
/* 		) */
/* 	yvideo $(syp $query) $folder */
/* } */





/* // Watch youtube videos over command line */
/* function global:yt { */
/* 	$search = "" */
/* 	do { */
/* 		$query = Read-Host "Search for a video" */
/* 		if ($query) { */
/* 			$search = $query */
/* 		} */
/* 		if ($search -and !($search.equals("exit"))) { */
/* 			$selection = $(syt $search) */
/* 			if ($selection) { */
/* 				mpv $selection --no-terminal */
/* 			} */
/* 		} */
/* 	} until ($search.equals("exit")) */
/* } */

/* function global:help { */
/* 	echo "YT -- Authored by Mitch Feigenbaum" */
/* 	echo "Options:" */
/* 	echo "`ti`t`tRun in interactive search mode" */
/* 	echo "`ta`t`tDownload audio from YouTube" */
/* 	echo "`tv`t`tDownload video from YouTube" */
/* 	echo "`tap`t`tDownload an audio playlist from YouTube" */
/* 	echo "`tvp`t`tDownload a video playlist from YouTube" */
/* 	echo "`th`t`tPrint this help message" */
/* } */

/* Switch ($option) { */
/* 	"i" {yt; break} */
/* 	"a" {da; break} */
/* 	"v" {dv; break} */
/* 	"ap" {dap; break} */
/* 	"vp" {dvp; break} */
/* 	Default {help} */
/* } */
#include <mpv/client.h>

#define YTAPIKEY "AIzaSyAr9WbWmgDQ4EkMBS4AsWj9ikkKODNZs78"
mpv_handle *ctx;

static inline void
check_error(int status) {
	if (status < 0) {
		fprintf(stderr, "mpv API error: %s\n", mpv_error_string(status));
		exit(1);
	}
}

void
ctx_make() {
	*ctx = mpv_create();
	if (!ctx) {
		fputs("failed creating context\n", stderr);
		exit(1);
	}
}

void
help() {
	puts("YT -- Authored by Mitch Feigenbaum\n\
Options:\n\
\ti\t\tRun in interactive search mode\n\
\ta\t\tDownload audio from YouTube\n\
\tv\t\tDownload video from YouTube\n\
\tap\t\tDownload an audio playlist from YouTube\n\
\tvp\t\tDownload a video playlist from YouTube\n\
\th\t\tPrint this help message\n");
}

int
main(int argc, char **argv) {
	if (argc == 1) {
		help();
		return 1;
	}
	int c;
	while ((c = getopt(argc, argv, "iavph")) != -1)
		switch(c) {
		case 'i':
			ctx_make();
			// video player function
			mpv_terminate_destroy(ctx);
			break;
		case 'a':
			break;
		case 'v':
			break;
		case 'p':
			break;
		case 'h':
			help();
			break;
		default:
			abort();
		}
	for(int i = optind; i < argc; i++)
		fprintf(stderr, "non-option argument: %s\n", argv[i]);
	return 0;
}

