const char* ConfFileSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
      "wss_certificate_file": {"type": "string"},
      "wss_private_key_file": {"type": "string"},
      "wss_dh_params_file": {"type": "string"},
      "wss_password": {"type": "string"},
      "http_proxy_server": {"type": "string", "minLength": 2},
	  "ws_port": {"type": "integer", "minimum": 2000 },
	  "wss_port": {"type": "integer", "minimum": 2000 },
      "request_subject": {"type": "string", "minLength": 5}
    },
	"anyOf": [{"required": ["ws_port"]},{"required": ["wss_port"]}],
    "required": ["wss_certificate_file","wss_private_key_file","wss_dh_params_file"]
})";

const char* IraRequestSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
      "event_name": {"type": "string", "pattern": "^request_" },
      "event_data": {"type": "object"}
    },
    "required": [ "event_name", "event_data"]
})";