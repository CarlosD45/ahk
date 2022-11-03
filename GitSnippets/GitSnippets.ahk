#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
; #Warn  ; Enable warnings to assist with detecting common errors.
SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.

::gst::
    Send, git status
    return
:O:gcom::
    Send, git commit -m ""
    return
::gad::
    Send, git add .
    return
::gpush::
    Send, git push
    return
::gpul::
    Send, git pull
    return
::gmer::
    Send, git merge
    return
::gclon::
    Send, git clone 
    Return
