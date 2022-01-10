df_check_location='/home'

    # get all the infos first to avoid high resources usage
    free_output=$(free -h | grep Mem)
    df_output=$(df -h $df_check_location | tail -n 1)

    # Used and total memory
    MEMUSED=$(echo $free_output | awk '{print $3}')
    MEMTOT=$(echo $free_output | awk '{print $2}')

    printf " %s %s " $MEMUSED" / "$MEMTOT""
