# TelemetryManagementAPI

All URIs are relative to *http://ufm.nvidia*

Method | HTTP request | Description
------------- | ------------- | -------------
[**TelemetryManagementAPI_getAllTelemetries**](TelemetryManagementAPI.md#TelemetryManagementAPI_getAllTelemetries) | **GET** /management/key_value | List history
[**TelemetryManagementAPI_updateTelemetry**](TelemetryManagementAPI.md#TelemetryManagementAPI_updateTelemetry) | **POST** /management/key_value | Add json data in format: {&#39;key&#39;:&#39;$KEY&#39;,&#39;value&#39;: $JSON_OBJ}


# **TelemetryManagementAPI_getAllTelemetries**
```c
// List history
//
list_t* TelemetryManagementAPI_getAllTelemetries(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[list_t](object.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **TelemetryManagementAPI_updateTelemetry**
```c
// Add json data in format: {'key':'$KEY','value': $JSON_OBJ}
//
void TelemetryManagementAPI_updateTelemetry(apiClient_t *apiClient, object_t * body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**body** | **[object_t](object.md) \*** |  | 

### Return type

void

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

