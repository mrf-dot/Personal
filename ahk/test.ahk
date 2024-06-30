#MaxThreadsPerHotkey 2
F12::
        toggle:=!toggle
        While toggle{
                send s
                sleep 1
        }
Return
