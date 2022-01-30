# Install software automatically with scoop
scoop install mingit
scoop bucket add extras
scoop bucket add java
scoop install aria2
scoop install ffmpeg
scoop install nodejs
scoop install openjdk
scoop install curl
scoop install windows-terminal
scoop install neovim
scoop install autohotkey
scoop install pwsh
scoop install figlet
scoop install rainbow
scoop install yt-dlp
scoop install mpv
scoop install youtube-dl
scoop install python
scoop install scoop-search
scoop install wkhtmltopdf

# Install mpv config
mkdir $env:userprofile\scoop\persist\mpv\portable_config
Invoke-WebRequest -Uri "https://raw.githubusercontent.com/mrf-dot/linuxize-school-pc/main/src/conf/mpv.conf" -Outfile "$env:userprofile\scoop\persist\mpv\portable_config\mpv.conf"

# Install powershell startup script
Invoke-WebRequest -Uri "https://raw.githubusercontent.com/mrf-dot/linuxize-school-pc/main/src/powershell/p.ps1" -Outfile "$env:userprofile\p.ps1"

# Install windows-terminal profile
mkdir "$env:LocalAppData\Microsoft\Windows Terminal"
Invoke-WebRequest -Uri "https://raw.githubusercontent.com/mrf-dot/linuxize-school-pc/main/src/json/settings.json" -OutFile "$env:LocalAppData\Microsoft\Windows Terminal\settings.json"

# Install vim-plug
iwr -useb https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim |`
    ni "$(@($env:XDG_DATA_HOME, $env:LOCALAPPDATA)[$null -eq $env:XDG_DATA_HOME])/nvim-data/site/autoload/plug.vim" -Force

# Install vim config
mkdir $env:LocalAppData/nvim
Invoke-WebRequest -Uri "https://raw.githubusercontent.com/mrf-dot/linuxize-school-pc/main/src/vimscript/init.vim" -Outfile "$env:localappdata\nvim\init.vim"

# Install all of the vim-plugins in my vim config
nvim -c "PlugInstall | quitall"

# Download FiraCode NF
Invoke-WebRequest "https://github.com/ryanoasis/nerd-fonts/blob/master/patched-fonts/FiraCode/Regular/complete/Fira%20Code%20Regular%20Nerd%20Font%20Complete%20Windows%20Compatible.ttf?raw=true" -OutFile "$env:userprofile/Downloads/FiraCode-NF.ttf"
