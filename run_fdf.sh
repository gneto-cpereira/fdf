#!/bin/bash

BLUE='\e[0;36;40m'
NC='\033[0m'

# Build docker image if not build yet
if [[ "$(sudo docker images -q fdf 2> /dev/null)" == "" ]]; then
    echo -e "${BLUE}Building Docker image for the first time...${NC}"
    sudo docker build -t fdf .

    # Exit if Docker fails
    if [[ $? -ne 0 ]]; then
        exit 1
    fi
fi

# Authorize X11
xhost +local:docker > /dev/null

# User input loop
while true; do
    clear
    echo -e "${BLUE}\n--- FdF Launcher ---${NC}"

    # List maps and create menus
    MAPS_DIR="maps"
    MAPS=($(ls $MAPS_DIR/*.fdf))

    echo -e "${BLUE}\nAvailable maps:${NC}"
    for i in "${!MAPS[@]}"; do
        printf "  ${BLUE}[%d]${NC} %s\n" "$i" "${MAPS[$i]##*/}"
    done

    # Read user choice
    echo -en "\nPress ${BLUE}q${NC} to exit"
    echo -en "\nChoose a map number: ${BLUE}"
    read index
    echo -e "${NC}"

    # If 'q' exit loop
    if [[ "$index" == "q" ]]; then
        break
    fi

    # Invalid number
    if [[ ! "$index" =~ ^[0-9]+$ ]] || [[ -z "${MAPS[$index]}" ]]; then
        echo -e "${BLUE}Invalid choice. Please enter a number from the list.${NC}"
        sleep 2
    # Valid number
    else
        SELECTED_MAP=${MAPS[$index]}

        # Execute Docker
        clear
        echo -e "${BLUE}Launching FdF with $SELECTED_MAP...${NC}"
        sudo docker run -it --rm \
            -e DISPLAY=$DISPLAY \
            -v /tmp/.X11-unix:/tmp/.X11-unix \
            fdf \
            ./fdf "$SELECTED_MAP"
    fi


done