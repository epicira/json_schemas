
const char* ConfFileSchema = R"(
{
  "$schema": "http://json-schema.org/draft-07/schema#",
  "type": "object",
  "properties": {
    "eventlog_days": {"type": "integer", "minimum": 0},
    "dial_timeout": {"type": "integer", "minimum": 0},
    "max_dial_ports": {"type": "integer", "minimum": 0},
    "cpa_init_tone": {"type": "string"},
    "cpa_port": {"type": "string"},
    "cpa_server": {"type": "string"},
	"native_load_balance": {"type": "boolean", "enum" : [true,false] },
    "request_queue": {"type": "string"},
    "polly_access_key": {"type": "string"},
    "polly_secret_id": {"type": "string"},
    "sip_fields": {
      "type": "array",
      "items": {
        "type": "object",
        "properties": {
          "event": {"type": "string"},
          "fields": {
            "type": "array",
            "items": {
              "type": "object",
              "properties": {
                "sip_field": {"type": "string"},
                "var_name": {"type": "string"}
              },
              "required": ["sip_field", "var_name"]
            }
          }
        },
        "required": ["event", "fields"]
      }
    }
  }
})";


namespace dialer
{
const char* IraDialerMakeCallSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": 
    {
        "event_name": {"type": "string", "enum": ["request_make_call"]},
        "event_data": 
        {
            "type": "object",
            "properties": 
            {
                "gateway": {"type": "string"},
                "to_number": {"type": "string"},
                "from_number": {"type": "string"},
                "tenant_id": {"type": "string"},
                "event_subject": {"type": "string"},
                "dial_timeout": {"type": "integer", "minimum": 5},
                "call_uuid": {"type": "string", "pattern": "^[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}$"},
                "conf_uuid": {"type": "string", "pattern": "^CONF-[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}$"},
                "add_to_conf": {"type": "string", "pattern": "^[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}$"},
				"join_conf": {"type": "boolean", "enum" : [true,false] },
                "cpa_config": {"type": "string"},
                "call_params": {"type": "object"}
            },
            "required": ["call_uuid","gateway", "to_number", "from_number", "tenant_id", "event_subject"]
        }
    },
    "required": ["event_name", "event_data"]
})";


const char* IraDialerBridgeCallSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": 
    {
        "event_name": {"type": "string", "enum": ["request_bridge_call"]},
        "event_data": 
        {
            "type": "object",
            "properties": 
            {
                "call_uuid": {"type": "string", "pattern": "^[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}$"},
                "conf_uuid": {"type": "string", "pattern": "^CONF-[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}$"},
                "event_subject": {"type": "string"}
            },
            "required": ["call_uuid", "conf_uuid"]
        }
    },
    "required": ["event_name", "event_data"]
})";

const char* IraDialerSimpleCallActionSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": 
    {
        "event_name": 
        {
            "type": "string", 
            "enum": 
            [
                "request_drop_call",
                "request_stop_play",
                "request_get_call_details",
                "request_mute_call",
                "request_unmute_call",
                "request_earmuff_on",
                "request_earmuff_off",
                "request_deaf_call",
                "request_undeaf_call",
                "request_hold_call",
                "request_unhold_call",
                "request_park_call"
            ]
        },
        "event_data": 
        {
            "type": "object",
            "properties": 
            {
                "call_uuid": 
                {
                    "type": "string", 
                    "pattern": "^[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}$"
                },
                "event_subject": 
                {
                    "type": "string"
                }
            },
            "required": ["call_uuid"]
        }
    },
    "required": ["event_name", "event_data"]
})";

const char* IraDialerPlayTTSSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": 
    {
        "event_name": {"type": "string", "enum": ["request_play_tts"]},
        "event_data": 
        {
            "type": "object",
			"properties": {
				"call_uuid": {"type": "string", "pattern": "^[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}$"},
				"stop_on_key": {"type": "boolean", "enum" : [true,false] },
				"loop_count": {"type": "integer", "minimum": 1 },
				"text": {"type": "string"},
				"tts_voice": {"type": "string"},
				"tts_engine": {"type": "string"},
				"event_subject": {"type": "string"}
			},
			"required": [ "call_uuid", "text" ]
        }
    },
    "required": ["event_name", "event_data"]
})";

const char* IraDialerPlayUrlSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": 
    {
        "event_name": {"type": "string", "enum": ["request_play_url"]},
        "event_data": 
        {
            "type": "object",
			"properties": {
				"call_uuid": {"type": "string", "pattern": "^[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}$"},
				"stop_on_key": {"type": "boolean", "enum" : [true,false] },
				"loop_count": {"type": "integer", "minimum": 1 },
				"url": {"type": "string"},
				"event_subject": {"type": "string"}
			},
			"required": [ "call_uuid", "url" ]
        }
    },
    "required": ["event_name", "event_data"]
})";


const char* IraDialerPlayFileSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": 
    {
        "event_name": {"type": "string", "enum": ["request_play_file"]},
        "event_data": 
        {
            "type": "object",
			"properties": {
				"call_uuid": {"type": "string", "pattern": "^[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}$"},
				"stop_on_key": {"type": "boolean", "enum" : [true,false] },
				"loop_count": {"type": "integer", "minimum": 1 },
				"filename": {"type": "string"},
				"event_subject": {"type": "string"}
			},
			"required": [ "call_uuid", "filename" ]
        }
    },
    "required": ["event_name", "event_data"]
})";

const char* IraDialerGetValidDTMFSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": 
    {
        "event_name": {"type": "string", "enum": ["request_get_valid_dtmf"]},
        "event_data": 
        {
            "type": "object",
			"properties": {
				"call_uuid": {"type": "string", "pattern": "^[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}$"},
				"var_name": {"type": "string"},
				"minimum_digits": {"type": "integer", "minimum":1 },
				"maximum_digits": {"type": "integer", "minimum": 1 },
				"minimum_tries": {"type": "integer", "minimum": 1 },
				"timeout": {"type": "integer", "minimum": 5 },
				"term_keys": {"type": "string"},
				"reg_expr": {"type": "string"},
				"audio_type": {"type": "string", "enum" : ["tts", "file", "url"] },
				"prompt_message": {"type": "string"},
				"error_message": {"type": "string"},
				"tts_voice": {"type": "string"},
				"tts_engine": {"type": "string"},
				"event_subject": {"type": "string"}
			},
			"required": [ "call_uuid", "var_name", "audio_type" ]
        }
    },
    "required": ["event_name", "event_data"]
})";


const char* IraDialerGetSimpleDTMFSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": 
    {
        "event_name": {"type": "string", "enum": ["request_get_simple_dtmf"]},
        "event_data": 
        {
            "type": "object",
			"properties": {
			  "call_uuid": {"type": "string", "pattern": "^[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}$"},
			  "var_name": {"type": "string"},
			  "digit_count": {"type": "integer", "minimum":1 },
			  "timeout": {"type": "integer", "minimum": 5 },
			  "term_keys": {"type": "string"},
			  "event_subject": {"type": "string"}
			},
		  "required": [ "call_uuid","var_name" ]
        }
    },
    "required": ["event_name", "event_data"]
})";


const char* IraDialerCreateGatewaySchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": 
    {
        "event_name": {"type": "string", "enum": ["request_create_gateway"]},
        "event_data": 
        {
            "type": "object",
				"properties": {
				  "gateway": {"type": "string"},
				  "ip_address": {"type": "string"},
				  "one_way": {"type": "boolean", "enum" : [true,false] }
				},
			  "required": [ "gateway","ip_address", "one_way"]
        }
    },
    "required": ["event_name", "event_data"]
})";

const char* IraDialerSendDTMFSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": 
    {
        "event_name": {"type": "string", "enum": ["request_send_dtmf"]},
        "event_data": 
        {
            "type": "object",
            "properties": 
            {
                "call_uuid": {"type": "string", "pattern": "^[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}$"},
                "digits": {"type": "string"}
            },
            "required": ["call_uuid", "digits"]
        }
    },
    "required": ["event_name", "event_data"]
})";

const char* IraDialerDirectBridgeSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": 
    {
        "event_name": {"type": "string", "enum": ["request_direct_bridge"]},
        "event_data": 
        {
			"type": "object",
			"properties": {
			  "call_uuid": {"type": "string", "pattern": "^[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}$"},
			  "gateway": {"type": "string"},
			  "to_number": {"type": "string"},
			  "from_number": {"type": "string"},
			  "dial_timeout": {"type": "integer", "minimum": 5}
			},
		  "required": [ "gateway", "to_number", "from_number", "call_uuid" ]
        }
    },
    "required": ["event_name", "event_data"]
})";

const char* AddSipGatewayDefSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": 
    {
        "event_name": {"type": "string", "enum": ["request_add_sip_gateway_def"]},
        "event_data": 
        {
			"type": "object",
			"properties": {
				"name": {"type": "string", "minLength": 2, "maxLength": 30},
				"sip_profile": {"type": "string", "minLength": 2, "maxLength": 15},
				"gateway_definition": {"type": "string"},
				"sip_proxy": {"type": "string"},
				"dialer_ip_list": { "type": "array","items": [{"type": "string"}]}
			},
			"required": [ "name", "sip_profile", "gateway_definition", "dialer_ip_list" ]
        }
    },
    "required": ["event_name", "event_data"]
})";

const char* DeleteSipGatewaySchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": 
    {
        "event_name": {"type": "string", "enum": ["request_delete_sip_gateway"]},
        "event_data": 
        {
			"type": "object",
			"properties": {
				"name": {"type": "string", "minLength": 2, "maxLength": 30},
				"sip_profile": {"type": "string", "minLength": 2}
			},
			"required": [ "name", "sip_profile"]
        }
    },
    "required": ["event_name", "event_data"]
})";

const char* InstanceActivationSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": 
    {
        "event_name": {"type": "string", "enum": ["request_activation"]},
        "event_data": 
        {
			"type": "object",
			"properties": 
			{
				"activate": {"type": "boolean", "enum" : [true,false] }
			},
			"required": ["activate"]
        }
    },
    "required": ["event_name", "event_data"]
})";

const char* HangupEventConfirmationSchema = R"(
{
	"$schema": "http://json-schema.org/draft-07/schema#",
	"type": "object",
	"properties": {
		"event_name": {"type": "string", "enum": ["hangup_event_confirmation"] },
		"event_data": {"type": "object",
		"properties" : {
			"call_uuid": {"type": "string", "pattern": "^[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}$"}
		},
		"required": ["call_uuid"] 
		}
	},
	"required": [ "event_name", "event_data"]
})";

}
