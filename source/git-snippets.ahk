#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
; #Warn  ; Enable warnings to assist with detecting common errors.
SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.

; Main Stream
::gst::
    Send, git status
    return
::gad::
    Send, git add .
    return
:O:gcom::
    Send, git commit -m ""
    return


; Branching
::gsw::
    Send, git switch" 
    Return
::gbr::
    Send, git branch 
    Return
::gmer::
    Send, git merge 
    return


; Remote
::gft::
    Send, git fetch
    Return
::gpul::
    Send, git pull
    return
::gpush::
    Send, git push
    return
::gclon::
    Send, git clone 
    Return
::grm::
    Send, git remote
    Return
::grmad::
    Send git remote add 
    Return
::gset::
    Send, git push -u origin 
    Return

;Config
::gconf::
    Send, git config --global -e
    Return
::gconfl::
    Send, git config --local -e
    Return

; Others
::glog::
    Send, git log --oneline
    Return

