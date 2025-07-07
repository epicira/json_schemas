
const char* ConfFileSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
      "tenant_id": {"type": "string", "minLength": 2, "maxLength": 50},
      "event_subject": {"type": "string", "minLength": 5},
      "sip_fields": {
        "type": "array",
        "items": [
          {
            "type": "object",
            "properties": {   
                  "sip_field": { "type": "string" }, 
                  "var_name": { "type": "string" }
             },
            "required": [ "sip_field", "var_name" ]
          }
        ]
      },
      "profiles": {
        "type": "array",
		"minItems": 1,
        "uniqueItems": true,
		"items": [
          {
            "type": "object",
            "properties": {   
				  "enable": {"type": "boolean", "enum" : [true,false] },
                  "name": { "type": "string" }, 
				  "proxy_host": {"type": "string", "minLength": 7, "maxLength": 50},
				  "tls_cert_dir": {"type": "string", "minLength": 2, "maxLength": 200},
				  "tls_password": {"type": "string", "minLength": 2, "maxLength": 100},
				  "proxy_sip_port": {"type": "integer", "minimum": 2000 },
				  "enable_reinvite": {"type": "boolean", "enum" : [true,false] },
				  "enable_server_rport": {"type": "boolean", "enum" : [true,false] },
				  "enable_client_rport": {"type": "boolean", "enum" : [true,false] },
				  "sip_log_filename": {"type": "string", "minLength": 5, "maxLength": 200}
             },
            "required": [ "name", "proxy_sip_port" ]
          }
        ]
      }
    },
    "required": [ "tenant_id", "profiles"]
})";

const char* UpdateTapperDetailsSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
			"event_name": {"type": "string","enum": ["request_update_tapper_details"]},
			"event_data": {"type": "object",
			"properties": 
			{
			  "tapper_pod_id": {"type": "string"},
			  "network_ip": {"type": "string"},
			  "external_ip": {"type": "string"},
			  "sip_port": {"type": "string"},
			  "tls_port": {"type": "string"},
			  "max_channels": {"type": "integer"},
			  "used_channels": {"type": "integer"},
			  "tapper_state": {"type": "boolean"}
			},
			"required": ["network_ip","external_ip","sip_port","tls_port","tapper_pod_id","max_channels","used_channels","tapper_state"]
		}
    },
    "required": ["event_name", "event_data"]
})";
