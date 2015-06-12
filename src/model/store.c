#include "store.h"

// Sets up default variables for store
void store_init() {
    // strcpy(bus_stops_list[0], "Stop 1");
    // strcpy(bus_stops_list[1], "Stop 2");
    // strcpy(bus_stops_list[2], "Stop 3");
    // strcpy(bus_stops_list[3], "Stop 4");

    // strcpy(services_list[0], "Service 1");
    // strcpy(services_list[1], "Service 2");
    // strcpy(services_list[2], "Service 3");
    // strcpy(services_list[3], "Service 4");
    
}

void services_list_reset() {
    memset(services_list, 0, sizeof services_list);
}

void bus_stop_list_reset() {
    memset(bus_stop_string_buffer, 0, sizeof bus_stop_string_buffer);
    memset(bus_stop_list, 0, sizeof bus_stop_list);   
}

int numberOfServices() {
    int arraySize = sizeof(services_list) / sizeof(services_list[0]);
    int counter = 0;
    for (int index = 0; index < arraySize; index++) {
        char *currentElement = services_list[index];
        if ((int)strlen(currentElement) > 0) {
            counter++;
        }
    }
    return counter;
}

int numberOfBusStops() {
    int arraySize = sizeof(bus_stop_string_buffer) / sizeof(bus_stop_string_buffer[0]);
    int counter = 0;
    for (int index = 0; index < arraySize; index++) {
        char *currentElement = bus_stop_string_buffer[index];
        if ((int)strlen(currentElement) > 0) {
            counter++;
        }
    }
    return counter;
}

void split_bus_stop_data() {

    int noBusStops = numberOfBusStops();
    for (int j = 0; j < noBusStops; j++) {
        char *currentBusStopString = bus_stop_string_buffer[j];

           int spaceAt = 0;
            for (int i = 0; (unsigned)i < strlen(currentBusStopString); i++) {
                
                if (currentBusStopString[i] == ',') {
                    spaceAt = i;
                    break;
                }
            }

        for (int i = 0; (unsigned)i < strlen(currentBusStopString); i++) {
            char currentChar = currentBusStopString[i];
            if (i == spaceAt) {
                continue;
            }
            
            if (i < spaceAt) {
                bus_stop_list[j][0][i] = currentChar;
                
            } else {
                int subtitleIndex = i - spaceAt - 1;
                bus_stop_list[j][1][subtitleIndex] = currentChar;
            }
        }
    }

}