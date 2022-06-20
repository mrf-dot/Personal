" Set up vim-plug automatically
	if ! filereadable(system('echo -n "${XDG_CONFIG_HOME:-$HOME/.config}/nvim/autoload/plug.vim"'))
		echo "Downloading junegunn/vim-plug to manage plugins..."
		silent !mkdir -p ${XDG_CONFIG_HOME:-$HOME/.config}/nvim/autoload/
		silent !curl "https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim" > ${XDG_CONFIG_HOME:-$HOME/.config}/nvim/autoload/plug.vim
		autocmd VimEnter * PlugInstall
	endif
" Sets leader character to space
	let mapleader = ' '
" Imports my plugins
	call plug#begin(stdpath('config').'/autoload/plugged')
	Plug 'neoclide/coc.nvim', {'branch': 'release'}
	Plug 'junegunn/goyo.vim'
	Plug 'ap/vim-css-color'
	Plug 'qpkorr/vim-renamer'
	Plug 'tpope/vim-commentary'
	Plug 'vimwiki/vimwiki'
	Plug 'chrisbra/unicode.vim'
	Plug 'rootkiter/vim-hexedit'
	call plug#end()
" Buffer behavior
	set relativenumber number
	set signcolumn=number
	set splitbelow splitright
" Don't backup files
	set nobackup nowritebackup
" Unclutter the UI
	set noshowmode
	set noshowcmd
	let g:netrw_banner=0
	let g:gitblame_enabled=1
" Yank to clipboard
	set clipboard+=unnamedplus
" Enables autocompletion
	set path+=**
	set wildmenu
	set wildmode=longest,list,full
" Replace all is aliased to S
	nmap S :%s//g<Left><Left>
" Set leader characters
	nmap <silent> <leader>a :CocList diagnostics<CR>
	nmap <silent> <leader>b :call hexedit#ToggleHexEdit()<CR>
	nmap <silent> <leader>e :Lex<CR>
	nmap <silent> <leader>g :Goyo \| set linebreak<CR>
	nmap <silent> <leader>h :nohlsearch<CR>
	nmap <silent> <leader>o :setlocal spell! spelllang=en_us<CR>
	nmap <silent> <leader>r :Rename<CR>
" Remap arrow keys to buffer movement
	nmap <LEFT> <C-w>h
	nmap <DOWN> <C-w>j
	nmap <UP> <C-w>k
	nmap <RIGHT> <C-w>l
" Add unicode support to ga
	nmap ga <Plug>(UnicodeGA)
" Allow for updated diagnostic messages
	set updatetime=300
" Give more concise messages
	set shortmess+=acs
" Set plugin home directories
	let g:nvim_system_wide = 1
	let g:coc_data_home = stdpath('config').'/coc'
	let g:vimwiki_list = [{
				\ 'path': $userprofile.'\wiki\text',
				\ 'path_html': $userprofile.'\wiki\html',}]
" K shows coc diagnostics as well as vim help
	nnoremap <silent> K :call <SID>show_documentation()<CR>
	function! s:show_documentation() abort
		if (index(['vim','help'], &filetype) >= 0)
			execute 'h '.expand('<cword>')
		elseif (coc#rpc#ready())
			call CocActionAsync('doHover')
		else
			execute '!' . &keywordprg . " " . expand('<cword>')
		endif
	endfunction
" Use `[c` and `]c` to navigate diagnostics
	nmap <silent> [c <Plug>(coc-diagnostic-prev)
	nmap <silent> ]c <Plug>(coc-diagnostic-next)
" Use `:Format` to format current buffer
	command! -nargs=0 Format :call CocAction('format')
" use `:OR` for organize import of current buffer
	command! -nargs=0 OR :call CocAction('runCommand', 'editor.action.organizeImport')
" Install lsps by default
	let g:coc_global_extensions=['coc-html', 'coc-java', 'coc-json', 'coc-marketplace', 'coc-pyright']

augroup DeleteWhitespace
	autocmd!
	autocmd BufWritePre * let currPos = getpos(".")
	autocmd BufWritePre * %s/\s\+$//e
	autocmd BufWritePre * %s/\n\+\%$//e
	autocmd BufWritePre *.[ch] %s/\%$/\r/e
	autocmd BufWritePre * call cursor(currPos[1], currPos[2])
augroup END

augroup Prose
	autocmd!
	autocmd BufRead,BufNewFile *.ms,*.me,*.mom,*.man set filetype=groff
	autocmd BufRead,BufNewFile *.ms,*.me,*.mom,*.man,*.md,*.wiki set textwidth=79
	autocmd BufRead,BufNewFile *.md,*.wiki set nowrap
augroup END

augroup CShortcuts
	autocmd!
	autocmd FileType c imap _f for (int i = 0; i < z; i++) {<ESC>Fzcw
	autocmd FileType c imap _g if (argc == 1) {
				\<CR>help();
				\<CR>return 1;
				\<CR>}
 				\<CR>int c;
 				\<CR>while ((c = getopt(argc, argv, "z")) != -1)
 				\<CR>switch(c) {
 				\<CR>case 'h':
 				\<CR>help();
 				\<CR>break;
 				\<CR>case '?':
 				\<CR>default:
 				\<CR>return 1;
 				\<CR>}
 				\<CR>for (int i = optind; i < argc; i++)
 				\<CR>fprintf(stderr, "non-option argument: %s\n", argv[i]);<ESC>10kFzcwh
	autocmd FileType c imap _m int
				\<CR>main(int argc, char **argv) {
					\<CR>return 0;
					\<CR>}<ESC>kO
augroup END
augroup JavaShortcuts
	autocmd!
	autocmd FileType java imap <silent> _xc <C-R>=expand('%:t:r')<CR>
	autocmd FileType java imap _pc public class _xc {<CR>}<ESC>O
 	autocmd FileType java imap _psvm public static void main(String[] args) {<CR>}<ESC>O
	autocmd FileType java imap _po System.out.print(z);<ESC>Fzcw
	autocmd FileType java imap _pl System.out.println(z);<ESC>Fzcw
	autocmd FileType java imap _pf System.out.printf(z);<ESC>Fzcw
	autocmd FileType java imap _pe System.err.println(z);<ESC>Fzcw
	autocmd FileType java imap _f for (int i = 0; i < z; i++) {<ESC>Fzcw
	autocmd FileType java imap _t try {
				\<CR>z
				\<CR>} catch (Exception ex) {
				\<CR>ex.printStackTrace();
				\<CR>}<ESC>3k0fzcw
	autocmd FileType java imap _c public static final int
	autocmd FileType java imap _m System.currentTimeMillis()
	autocmd FileType java imap _s _tThread.sleep(z);<ESC>Fzcw
	autocmd FileType java imap _hi _pc_psvm_pl"Hello, world!"<ESC>G
augroup END

augroup HtmlShortcuts
	autocmd!
	autocmd Filetype html imap _html <!DOCTYPE html>
				\<CR><html lang="en">
				\<CR><head>
				\<CR><meta charset="UTF-8">
				\<CR><meta name="description" content="">
				\<CR><meta name="keywords" content="">
				\<CR><meta name="author" content="">
				\<CR><meta name="viewport" content="width=device-width, initial-scale=1.0">
				\<CR><title>z</title>
				\<CR></head>
				\<CR><body>
				\<CR></body>
				\<CR></html><ESC>4k0fzcw
	autocmd FileType html imap _a <a href="z"></a><ESC>Fzcw
	autocmd FileType html imap _b <b>z</b><ESC>Fzcw
	autocmd Filetype html imap _c <!-- z --><ESC>Fzcw
	autocmd FileType html imap _i <i>z</i><ESC>Fzcw
	autocmd FileType html imap _l <li>z</li><ESC>Fzcw
	autocmd FileType html imap _p <p>z</p><ESC>Fzcw
augroup END
