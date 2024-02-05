"        _                    
"       (_)                   
" __   ___ _ __ ___  _ __ ___ 
" \ \ / / | '_ ` _ \| '__/ __|
"  \ V /| | | | | | | | | (__ 
"   \_/ |_|_| |_| |_|_|  \___|
"                             
"
:set number relativenumber
:syntax enable
:set autoindent
syntax on
colorscheme nord
set nocompatible
filetype plugin on
:set fileformat=unix
:set clipboard+=unnamedplus
set termguicolors

" set mapleader
:let mapleader = " "
":let maplocalleader = "\\"

" set quick leader bindings
:map <Leader>w :w<LF>
:map <Leader>q :q<LF>

" compiling latex from vim
:map <Leader>lc :w<LF>:!pdflatex -shell-escape %<LF>

" leader bindings for latex
:map <Leader>idi :norm i\iint{}<esc>i

" Launch lsp

"lua << EOF
"require'lspconfig'.pyright.setup{}
"require'lspconfig'.gopls.setup{}
"EOF

" vim lightline
set laststatus=2
set noshowmode
"set guifont=Hack\ Nerd\ Font\ 11
let g:lightline = {
	\ 'colorscheme': 'nord',
	\ 'active': {
	\	'left': [ [ 'mode' ], [ 'filename', 'readonly', 'modified' ] ],
	\	'right': [ [ 'lineinfo' ],
	\		   [ 'percent' ],
	\		   [ 'fileencoding', 'charvaluehex', 'filetype' ] ]
	\ },
	\ 'component': {
	\	'charvaluehex': '0x%B'
	\ },
	\ 'separator': { 'left': '', 'right': '' },
	\ 'subseparator': { 'left': "", 'right': "" },
	\ }

" Duration of a pomodoro in minutes (default: 25)
let g:pomodoro_time_work = 45

" Duration of a break in minutes (default: 5)
let g:pomodoro_time_slack = 10

" Log completed pomodoros, 0 = False, 1 = True (default: 0)
let g:pomodoro_do_log = 1 

" Path to the pomodoro log file (default: /tmp/pomodoro.log)
let g:pomodoro_log_file = "/tmp/pomodoro.log"

" Display remaining time in statusbar
set statusline=%#ErrorMsg#%{pomo#status_bar()}%#StatusLine#

let g:pomodoro_notification_cmd = "mpg123 -q ~/.config/nvim/pack/plugins/start/pomodoro.vim/pomodoro.mp3"
