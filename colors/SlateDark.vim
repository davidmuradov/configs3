"%% SiSU Vim color file
" SlateDark Maintainer: Rudra Banerjee <bnrj.rudra@yahoo.com> 
" Originally inspired from Slate by Ralph Amissah
:set background=dark
highlight clear
if version > 580
 hi clear
 if exists("syntax_on")
 syntax reset
 endif
endif
let colors_name = "SlateDark"
hi Normal guifg=#ffffff guibg=#262626
hi Cursor guibg=#ffffff guifg=#000000
hi VertSplit guibg=#c2bfa5 guifg=grey40 gui=none cterm=reverse
hi Folded guibg=black guifg=grey40 ctermfg=grey ctermbg=darkgrey
hi FoldColumn guibg=black guifg=grey20 ctermfg=4 ctermbg=7
hi IncSearch guifg=green guibg=black cterm=none ctermfg=yellow ctermbg=green
hi ModeMsg guifg=goldenrod cterm=none ctermfg=brown
hi MoreMsg guifg=SeaGreen ctermfg=200
hi NonText guifg=RoyalBlue guibg=grey15 cterm=bold ctermfg=105
hi Question guifg=springgreen ctermfg=192
hi Search guibg=peru guifg=wheat cterm=none ctermfg=grey ctermbg=blue
hi SpecialKey guifg=yellowgreen ctermfg=200
hi StatusLine guibg=#c2bfa5 guifg=black gui=none cterm=bold,reverse
hi StatusLineNC guibg=#c2bfa5 guifg=grey40 gui=none cterm=reverse
hi Title guifg=gold gui=bold cterm=bold ctermfg=yellow
hi Statement guifg=CornflowerBlue ctermfg=141
hi Visual gui=none guifg=khaki guibg=olivedrab cterm=reverse
hi WarningMsg guifg=salmon ctermfg=1
:hi String guifg=SkyBlue ctermfg=125
hi Comment term=bold ctermfg=63 guifg=grey40
hi Constant guifg=#ffa0a0 ctermfg=182
hi Special guifg=darkkhaki ctermfg=174
hi Identifier guifg=salmon ctermfg=200
hi Include guifg=red ctermfg=171
":hi PreProc guifg=red guibg=white ctermfg=red
"hi Operator guifg=Red ctermfg=Red
hi Define guifg=gold gui=bold ctermfg=yellow
hi Type guifg=CornflowerBlue ctermfg=168
hi Function guifg=navajowhite ctermfg=156
hi Structure guifg=green ctermfg=192
hi LineNr guifg=grey50 ctermfg=245 ctermbg=234
hi Ignore guifg=grey40 cterm=bold ctermfg=7
hi Todo guifg=orangered guibg=yellow2
hi Directory ctermfg=45
hi ErrorMsg cterm=bold guifg=White guibg=Red cterm=bold ctermfg=7 ctermbg=1
hi VisualNOS cterm=bold,underline
hi WildMenu ctermfg=0 ctermbg=3
hi DiffAdd ctermbg=4
hi DiffChange ctermbg=5
hi DiffDelete cterm=bold ctermfg=105 ctermbg=6
hi DiffText cterm=bold ctermbg=1
hi Underlined cterm=underline ctermfg=5
hi Error guifg=White guibg=Red cterm=bold ctermfg=7 ctermbg=1
hi SpellErrors cterm=bold ctermfg=7 ctermbg=1 gui=undercurl,bold
