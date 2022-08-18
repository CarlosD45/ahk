#SingleInstance, Force
#NoEnv
SendMode Input
SetWorkingDir, %A_ScriptDir%

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