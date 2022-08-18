#SingleInstance, Force
#NoEnv
SendMode Input
SetWorkingDir, %A_ScriptDir%

; Basic Git Snippets
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

; Directional Keys Remap
!i::
    Send, {Up}
    Return
!j::
    Send, {Left}
    Return
!l::
    Send, {Right}
    Return
!k::
    Send, {Down}
    Return