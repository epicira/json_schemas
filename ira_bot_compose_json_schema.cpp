const char* ConfFileSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
      "use_self_signed_certificate": {"type": "boolean", "enum" : [true,false] },
      "wss_certificate_file": {"type": "string"},
      "wss_private_key_file": {"type": "string"},
      "wss_dh_params_file": {"type": "string"},
      "wss_password": {"type": "string"},
      "http_proxy_server": {"type": "string", "minLength": 2},
	  "ws_port": {"type": "integer", "minimum": 2000 },
	  "wss_port": {"type": "integer", "minimum": 2000 },
      "request_subject": {"type": "string", "minLength": 5},
    },
	"anyOf": [{"required": ["ws_port"]},{"required": ["wss_port"]}],
    "required": ["use_self_signed_certificate"]
})";
