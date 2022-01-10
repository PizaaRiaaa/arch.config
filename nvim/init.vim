set nu
set t_Co=256
set cursorline
set incsearch
set ignorecase
set tabstop=3
set shiftwidth=3
set expandtab
set laststatus=2
set noswapfile
set nocompatible
filetype indent plugin on
syntax on

call plug#begin('~/.vim/plugged')
Plug 'uiiaoo/java-syntax.vim'
Plug 'neoclide/coc.nvim', {'branch': 'release'}
Plug 'majutsushi/tagbar'
Plug 'vimwiki/vimwiki'
Plug 'itchyny/lightline.vim'
Plug 'alvan/vim-closetag'
Plug 'SirVer/ultisnips'
Plug 'honza/vim-snippets'
Plug 'scrooloose/nerdtree', { 'on':  'NERDTreeToggle' }
Plug 'ryanoasis/vim-devicons'
Plug 'morhetz/gruvbox'
Plug 'pineapplegiant/spaceduck', { 'branch': 'main' }
Plug 'dracula/vim',{'as':'dracula'}
Plug 'nvim-lua/popup.nvim'
Plug 'nvim-lua/plenary.nvim'
Plug 'nvim-telescope/telescope.nvim'
call plug#end()
Plug 'pineapplegiant/spaceduck', { 'branch': 'main' }

autocmd FileType java setlocal omnifunc=javacomplete#Complete
    
 let g:closetag_filenames = '*.html,*.xhtml,*.phtml'
 let g:closetag_xhtml_filenames = '*.xhtml,*.jsx'
 let g:closetag_filetypes = 'html,xhtml,phtml'
 let g:closetag_xhtml_filetypes = 'xhtml,jsx'
 let g:closetag_emptyTags_caseSensitive = 1
 let g:closetag_regions = {
     \ 'typescript.tsx': 'jsxRegion,tsxRegion',
     \ 'javascript.jsx': 'jsxRegion',
     \ }

 let g:closetag_shortcut = '>'
 let g:closetag_close_shortcut = '<leader>>'
 "==========================================
 autocmd BufWritePost *.tex silent! execute "!pdflatex % >/dev/null 2>&1" | redraw!

" COLORSCHEME ===================================================
   if exists('+termguicolors')
      let &t_8f = "\<Esc>[38;2;%lu;%lu;%lum"
      let &t_8b = "\<Esc>[48;2;%lu;%lu;%lum"
      set termguicolors
    endif


   colorscheme dracula

" TELESCOPE====================================================="
" " Find files using Telescope command-line sugar.
nnoremap <leader>ff <cmd>Telescope find_files<cr>
nnoremap <leader>fg <cmd>Telescope live_grep<cr>
nnoremap <leader>fb <cmd>Telescope buffers<cr>
nnoremap <leader>fh <cmd>Telescope help_tags<cr>

" AIRLINE ===================
 let g:lightline = {
        \ 'colorscheme': 'dracula',
        \ 'separator': { 'left': '', 'right': '' },
        \ 'subseparator': { 'left': '', 'right': '' }
        \ }

 "Ctrl-i to open Tagbar
 map <C-i> :TagbarToggle<CR>

 "autocomplete bracket
 inoremap { {}<ESC>ha
 inoremap [ []<ESC>ha
 inoremap " ""<ESC>ha
 inoremap ( ()<ESC>ha

 " Since we are already using Deoplete, and using tab with both doesn't work nice use <c-j> instead
 let g:UltiSnipsExpandTrigger="<c-j>"
 let g:UltiSnipsJumpForwardTrigger="<c-b>"
 let g:UltiSnipsJumpBackwardTrigger="<c-z>"

 " If you want :UltiSnipsEdit to split your window.
 let g:UltiSnipsEditSplit="vertical"
 let g:UltiSnipsSnippetDirectories = ['~/.config/nvim/UltiSnips', 'UltiSnips']
 let g:UltiSnipsSnippetsDir="~/.config/nvim/UltiSnips"

 " Always show tabs
 set showtabline=2
  " \1 \2 \3 : go to buffer 1/2/3 etc
 nnoremap 1 :1b<CR>
 nnoremap 2 :2b<CR>
 nnoremap 3 :3b<CR>
 nnoremap 4 :4b<CR>
 nnoremap 5 :5b<CR>
 nnoremap 6 :6b<CR>
 nnoremap 7 :7b<CR>
 nnoremap 8 :8b<CR>
 nnoremap 9 :9b<CR>
 nnoremap 0 :10b<CR>

 " It's useful to show the buffer number in the status line.
 set laststatus=2 statusline=%02n:%<%f\ %h%m%r%=%-14.(%l,%c%V%)\ %P

 let $FZF_DEFAULT_COMMAND = 'ag -g ""'
 let g:NERDTreeShowHidden = 1
 let g:NERDTreeMinimalUI = 1
 let g:NERDTreeIgnore = []
 let g:NERDTreeStatusline = ''
 let $FZF_DEFAULT_COMMAND = 'ag -g ""'
 let g:coc_global_extensions = ['coc-emmet', 'coc-css', 'coc-java', 'coc-html', 'coc-json', 'coc-prettier', 'coc-tsserver']


 " Automaticaly close nvim if NERDTree is only thing left open
 autocmd bufenter * if (winnr("$") == 1 && exists("b:NERDTree") && b:NERDTree.isTabTree()) | q | endif
 " Toggle Ctrl + B
 nnoremap <silent> <C-b> :NERDTreeToggle<CR>
 " open new split panes to right and below
 set splitright
 set splitbelow
 " turn terminal to normal mode with escape
 tnoremap <Esc> <C-\><C-n>
 " start terminal in insert mode
 au BufEnter * if &buftype == 'terminal' | :startinsert | endif
 " open terminal on ctrl+n
 function! OpenTerminal()
   split term://bash
   resize 10
 endfunction
 nnoremap <c-n> :call OpenTerminal()<CR>

 inoremap <silent><expr> <TAB>
       \ pumvisible() ? "\<C-n>" :
       \ <SID>check_back_space() ? "\<TAB>" :
       \ coc#refresh()
 inoremap <expr><S-TAB> pumvisible() ? "\<C-p>" : "\<C-h>"


 function! s:check_back_space() abort
   let col = col('.') - 1
   return !col || getline('.')[col - 1]  =~# '\s'
 endfunction

 " use alt+hjkl to move between split/vsplit panels
 tnoremap <C-h> <C-\><C-n><C-w>h
 tnoremap <C-j> <C-\><C-n><C-w>j
 tnoremap <C-k> <C-\><C-n><C-w>k
 tnoremap <C-l> <C-\><C-n><C-w>l
 nnoremap <s-h> <C-w>h
 nnoremap <s-j> <C-w>j
 nnoremap <s-k> <C-w>k
 nnoremap <s-l> <C-w>l

 "alternative for esc
 imap jj <Esc>

 map <F5> :call CompileRunGcc()<CR>
 func! CompileRunGcc()
 exec "w"
 if &filetype == 'c'
 exec "!gcc % -o %<"
 exec "!time ./%<"
 elseif &filetype == 'cpp'
 exec "!g++ % -o %<"
 exec "!time ./%<"
 elseif &filetype == 'java'
 exec "!javac %"
 exec "!time java -cp %:p:h %:t:r"
 elseif &filetype == 'sh'
 exec "!time bash %"
 elseif &filetype == 'python'
 exec "!time python2.7 %"
 elseif &filetype == 'html'
 exec "!firefox % &"
 elseif &filetype == 'go'
 exec "!go build %<"
 exec "!time go run %"
 elseif &filetype == 'mkd'
 exec "!~/.vim/markdown.pl % > %.html &"
 exec "!brave %.html &"
 endif
 endfunc
