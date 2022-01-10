 df_check_location='/home'

    free_output=$(free -h | grep Mem)
    df_output=$(df -h $df_check_location | tail -n 1)

    CPU=$(top -bn1 | grep Cpu | awk '{print $2}')%

    STOUSED=$(echo $df_output | awk '{print $3}')
    STOTOT=$(echo $df_output | awk '{print $2}')

 printf "%s %s" "$STOUSED" / $STOTOT""


