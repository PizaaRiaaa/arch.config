# If you come from bash you might have to change your $PATH.
# export PATH=$HOME/bin:/usr/local/bin:$PATH
export PATH="$PATH:/usr/local/bin"
export STARDICT_DATA_DIR="~/dictionaries"
export PATH="/home/pizaariaaa/.local/bin:$PATH"

# load zgen
source "${HOME}/.zgen/zgen.zsh"

# zgen ohmyzsh plugins
zgen oh-my-zsh
zgen oh-my-zsh plugins/git
zgen oh-my-zsh plugins/sudo
zgen oh-my-zsh plugins/command-not-found
zgen oh-my-zsh themes/dst

neofetch

source /usr/share/zsh/plugins/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh

# Lines configured by zsh-newuser-install
HISTFILE=~/.histfile2
HISTSIZE=1000
SAVEHIST=10003

bindkey -v
# End of lines configured by zsh-newuser-install
# The following lines were added by compinstall

zstyle :compinstall filename '/home/pizaariaaa/.zshrc'
autoload -Uz compinit
compinit
# End of lines added by compinstall


# aliases
# ctrl + t to open fuzzy finder
alias v="nvim"
alias vimwiki="v ~/vimwiki/index.wiki"
alias station="cd ~/documents/station"
alias zsh="source ~/.zshrc"
alias starttree="cd ~/documents/StartTree"
alias gen="./generate.py"
alias sx="source ~/.xinitrc"
alias define="sdcv --data-dir /usr/share/stardic/dic/stardict-merrianwebster-2.4.2"

[ -f ~/.fzf.zsh ] && source ~/.fzf.zsh
