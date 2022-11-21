slim_path=`dirname $0`
fpath=( $slim_path $fpath )

# export PATH=~/.local/bin:$PATH

HISTFILE=$slim_path/.HISTFILE
HISTSIZE=1000
SAVEHIST=1000
unsetopt beep
bindkey -v

autoload -U promptinit && promptinit
prompt pure
autoload -U colors && colors

# setopt promptsubst

export PF_SOURCE="${HOME}/.config/.zshenv"

export FZF_DEFAULT_OPTS='--color=fg:#DED7D0,bg:#1E1D23,hl:#EFD472 --color=fg+:#DED7D0,bg+:#413E41,hl+:#7EC49D --color=info:#8BB8D0,prompt:#7EC49D,pointer:#FF7DA3 --color=marker:#FF7DA3,spinner:#EFD472,header:#938884'

autoload -Uz compinit
compinit -C

setopt autocd
setopt extendedglob
setopt NO_NOMATCH

export CLICOLOR=1
export LESSHISTFILE=-

source $slim_path/keys.zsh
source $slim_path/history.zsh
source $slim_path/completion.zsh
source $slim_path/zsh-autosuggestions/zsh-autosuggestions.zsh
source $slim_path/aliases.zsh
source $slim_path/correction.zsh
source $slim_path/sudo.plugin.zsh
source $slim_path/stack.zsh
source $slim_path/fast-syntax-highlighting/fast-syntax-highlighting.plugin.zsh

