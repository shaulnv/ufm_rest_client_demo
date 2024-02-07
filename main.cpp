// std
#include <memory>
// generated rest client
extern "C" {
#include <api/TelemetryManagementAPI.h>
}

// c++ smart pointers, which wraps c's raws pointers
using apiClient_ptr = std::unique_ptr<apiClient_t, std::decay<decltype(apiClient_free)>::type>;
apiClient_ptr MakeUniquePtr(apiClient_t* p) { return {p, apiClient_free}; }

using object_ptr = std::unique_ptr<object_t, std::decay<decltype(object_free)>::type>;
object_ptr MakeUniquePtr(object_t* p) { return {p, object_free}; }

using cJSON_ptr = std::unique_ptr<cJSON, std::decay<decltype(cJSON_Delete)>::type>;
cJSON_ptr MakeUniquePtr(cJSON* p) { return {p, cJSON_Delete}; }

// simple use of ufm telemetry API
int main() {

  // create the client
  auto apiClient = MakeUniquePtr(apiClient_create_with_base_path("http://localhost:8000/", nullptr));

  // create sharp_am telemetry key-value
  auto telemetry = MakeUniquePtr(cJSON_CreateObject());
  auto* value = cJSON_CreateObject();
  cJSON_AddStringToObject(value, "key1", "value1");
  cJSON_AddNumberToObject(value, "key2", 123);

  cJSON_AddStringToObject(telemetry.get(), "key", "sharp_am");
  cJSON_AddItemToObject(telemetry.get(), "value", value);

  // print the telemetry key-value json
  // convert the cJSON object to a JSON string
  char* jsonString = cJSON_Print(telemetry.get());
  printf("%s\n", jsonString);
  free(jsonString);

  // send the telemetry
  auto ptr_telemetry = MakeUniquePtr(object_parseFromJSON(telemetry.get()));
  TelemetryManagementAPI_updateTelemetry(apiClient.get(), ptr_telemetry.get());

  return 0;
}