#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/object.h"


// List history
//
list_t*
TelemetryManagementAPI_getAllTelemetries(apiClient_t *apiClient);


// Add json data in format: {'key':'$KEY','value': $JSON_OBJ}
//
void
TelemetryManagementAPI_updateTelemetry(apiClient_t *apiClient, object_t *body);


