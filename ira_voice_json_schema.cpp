
const char* ConfFileSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
    "fs_event_log": {"type": "string", "enum": ["none","call_events","all_events"] },
	"dial_timeout": {"type": "integer"},
	"eventlog_days": {"type": "integer"},
	"max_dial_ports": {"type": "integer"},
	"cpa_init_tone": {"type": "string"},
	"cpa_port": {"type": "string"},
	"cpa_server": {"type": "string"},
	"request_queue": {"type": "string"},
	"onnx_model_path": {"type": "string"},
	"onnx_core_count": {"type": "integer"},
	"call_scheduler": {"type": "string", "enum": ["none","iracallscheduler"]},
	"botaudio_buffer_size": {"type": "integer", "minLength": 20, "maxLength": 120},
	"ira_http_proxy": {"type": "string"}
	},
	"required": [ ]
})";

namespace iravoice
{

const char* MakeCallSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
      "event_name": {"type": "string", "enum": ["request_make_call"] },
      "event_data": {"type": "object",
			"properties": {
			  "call_uuid": {"type": "string", "pattern": "^[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}$"},
			  "gateway": {"type": "string", "minLength": 2, "maxLength": 60},
			  "campaign": {"type": "string", "minLength": 2, "maxLength": 60},
			  "tenant_id": {"type": "string" , "minLength": 2, "maxLength": 20},
			  "to_number": {"type": "string", "minLength": 3, "maxLength": 25},
			  "from_number": {"type": "string", "maxLength": 25},
			  "event_subject": {"type": "string", "minLength": 2, "maxLength": 50},
			  "cpa_config": {"type": "string", "minLength": 0, "maxLength": 15},
			  "dial_timeout": {"type": "integer", "minimum": 5},
			  "channel_vars": {"type": "object"},
			  "call_params": {"type": "object"}
			},
			"required": [ "call_uuid", "gateway", "to_number", "tenant_id","event_subject" ]
		}
    },
    "required": [ "event_name", "event_data"]
})";

const char* BridgeCallsSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
      "event_name": {"type": "string", "enum": ["request_bridge_calls"] },
        "event_data": {"type": "object",
			"properties": {
				"first_uuid": {"type": "string", "pattern": "^[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}$"},
				"second_uuid": {"type": "string", "pattern": "^[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}$"}
			},
			"required": [ "first_uuid", "second_uuid"]
        }
    },
    "required": [ "event_name", "event_data"]
})";

const char* SimpleCallActionSchema = R"(
{
	"$schema": "http://json-schema.org/draft-07/schema#",
	"type": "object",
	"properties": {
		"event_name": {"type": "string", "enum": ["request_drop_call",
					"request_stop_stream","request_stop_record","request_stop_play"] },
		"event_data": {"type": "object",
		"properties": {
				  "call_uuid": {"type": "string", "pattern": "^[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}$"}
				},
			  "required": [ "call_uuid" ]
			}
		},
    "required": [ "event_name", "event_data"]
})";

const char* RecordActionSchema = R"(
{
	"$schema": "http://json-schema.org/draft-07/schema#",
	"type": "object",
	"properties": {
		"event_name": {"type": "string", "enum": ["request_start_record"] },
		"event_data": {"type": "object",
		"properties": {
			"call_uuid": {"type": "string", "pattern": "^[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}$"},
			"mp3_quality": {"type": "integer", "minimum": 0, "maximum": 9},
			"format": {"type": "string", "enum" : ["mp3","wav"] }
		},
		"required": [ "call_uuid" ]
		}
	},
    "required": [ "event_name", "event_data"]
})";

const char* RecordSiprecSchema = R"(
{
	"$schema": "http://json-schema.org/draft-07/schema#",
	"type": "object",
	"properties": {
		"event_name": {"type": "string", "enum": ["request_start_siprec_record"] },
		"event_data": {"type": "object",
		"properties": {
			"siprec_id": {"type": "string"},
			"file_name": {"type": "string"},
			"mp3_quality": {"type": "integer", "minimum": 0, "maximum": 9},
			"format": {"type": "string", "enum" : ["mp3","wav"] }
		},
		"required": [ "siprec_id","file_name" ]
		}
	},
    "required": [ "event_name", "event_data"]
})";

const char* StopRecordActionSchema = R"(
{
	"$schema": "http://json-schema.org/draft-07/schema#",
	"type": "object",
	"properties": {
		"event_name": {"type": "string", "enum": ["request_stop_record"] },
		"event_data": {"type": "object",
		"properties": {
			"siprec_id": {"type": "string"},
			"call_uuid": {"type": "string", "pattern": "^[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}$"}
		},
		"oneOf": [{"required": ["siprec_id"]},{"required": ["call_uuid"]}]
		}
	},
    "required": [ "event_name", "event_data"]
})";

const char* SetChannelVarsActionSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string","enum": ["request_set_channel_vars"]},
        "event_data": {"type": "object",
            "properties": {
                "call_uuid": {"type": "string","pattern": "^[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}$"},
                "channel_vars": {"type": "object"}
            },
            "required": ["call_uuid", "channel_vars"]
        }
    },
    "required": ["event_name", "event_data"]
})";

const char* StartStreamingSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string","enum": ["request_start_stream"]},
        "event_data": {"type": "object",
		"properties": {
			"call_uuid": {"type": "string", "pattern": "^[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}$"},
			"websocket_host": {"type": "string", "minLength": 2, "maxLength": 200},
			"websocket_app": {"type": "string", "minLength": 1, "maxLength": 200},
			"websocket_port": {"type": "integer"},
			"stream_frame_size_ms": {"type": "integer", "minimum": 100, "maximum": 400, "default": 200},
			"vad": {"type": "string", "enum" : ["no","dsp","onnx"] },
			"log_vad_events": {"type": "boolean", "enum" : [true,false], "default": false },
			"enable_pre_silence": {"type": "boolean", "enum" : [true,false], "default": false },
			"vad_max_speech_duration_sec" : {"type": "integer", "default": 60},
			"dsp_vad_params": {"type": "object",
			"properties": {
				"speech_threshold" : {"type": "integer", "minimum": 200, "maximum": 800, "default": 500, "description": "Threshold for speech detection"},
				"silence_threshold_ms" : {"type": "integer", "minimum": 200, "maximum": 2000, "default": 800, "description": "Threshold for silence detection"},
				"vad_audio_limit" : {"type": "integer", "minimum": 2, "default": 20, "description": "Don't change this"}
				}
			},
			"onnx_vad_params": {"type": "object",
			"properties": {
				"frame_size_ms" : {"type": "integer", "enum": [32,64,96], "default": 32, "description": "VAD processing Frame size in milliseconds"},
				"min_silence_ms" : {"type": "integer", "default": 600, "description": "Minimum silence duration in milliseconds"},
				"min_speech_ms" : {"type": "integer", "default": 250, "description": "Minimum speech duration in milliseconds"},
				"speech_threshold" : {"type": "number", "minimum": 0.4, "maximum": 0.9, "default": 0.6, "description": "Probability of speech"},
				"silence_threshold" : {"type": "number", "minimum": 0.05, "maximum": 0.35, "default": 0.2, "description": "Probability of silence"}
				}
			},
			"streaming_botaudio": {"type": "boolean", "enum" : [true,false] },
			"dropcall_on_break": {"type": "boolean", "enum" : [true,false] },
			"brotli_quality": {"type": "integer", "minimum": 0, "maximum": 11},
			"bot_inactivity_limit" : {"type": "integer", "minimum": 0, "maximum": 120},
			"more_call_params": {"type": "object"},
			"background_audio": {"type": "string"},
			"mix_factor": {"type": "number", "minimum": 0, "maximum": 1},
			"initial_botaudio_delay_threshold" : {"type": "integer", "minimum": 1, "maximum": 20}
		},
		"required": [ "call_uuid", "websocket_host", "websocket_port","vad" ]
        }
    },
    "required": ["event_name", "event_data"]
})";

const char* TransferCallSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string","enum": ["request_transfer_call"]},
        "event_data": {"type": "object",
			"properties": {
				"call_uuid": {"type": "string", "pattern": "^[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}$"},
				"deflect": {"type": "boolean", "enum" : [true,false] },
				"destination": {"type": "string", "minLength": 2, "maxLength": 100}
			},
			"required": [ "call_uuid", "destination"]
        }
    },
    "required": ["event_name", "event_data"]
})";

const char* PlayUrlSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string","enum": ["request_play_url"]},
        "event_data": {"type": "object",
			"properties": {
			  "call_uuid": {"type": "string", "pattern": "^[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}$"},
			  "url": {"type": "string", "minLength": 2}
			},
			"required": [ "call_uuid", "url"]
        }
    },
    "required": ["event_name", "event_data"]
})";

const char* PlayFileSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string","enum": ["request_play_file"]},
        "event_data": {"type": "object",
			"properties": {
			  "call_uuid": {"type": "string", "pattern": "^[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}$"},
			  "file": {"type": "string", "minLength": 2}
			},
			"required": [ "call_uuid", "file"]
        }
    },
    "required": ["event_name", "event_data"]
})";

const char* SnoopOnCallSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
			"event_name": {"type": "string","enum": ["request_snoop_on_call"]},
			"event_data": {"type": "object",
			"properties": {
			  "target_call_uuid": {"type": "string", "pattern": "^[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}$"},
			  "listener_call_uuid": {"type": "string", "pattern": "^[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}$"}
			},
			"required": [ "target_call_uuid", "listener_call_uuid" ]
        }
    },
    "required": ["event_name", "event_data"]
})";


const char* SelectSIPFieldsSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
		"event_name": {"type": "string","enum": ["request_select_sip_fields"]},
		"event_data": {"type": "object",
		"properties": {
		"sip_fields": {
			"type": "array",
			"items": [
					{
						"type": "object",
						"properties": {   
							"sip_event": { "type": "string" },
							"sip_field": { "type": "string" }, 
							"var_name": { "type": "string" }
						},
						"required": [ "sip_event", "sip_field", "var_name" ]
					}
				]
			},
			"hop_count": {"type": "integer"}
		},
		"required": ["sip_fields"]
        }
    },
    "required": ["event_name", "event_data"]
})";

const char* DeleteSIPFieldsSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
		"event_name": {"type": "string","enum": ["request_delete_sip_fields"]},
		"event_data": {"type": "object",
		"properties": {
		"sip_fields": {
			"type": "array",
			"items": [
					{
						"type": "object",
						"properties": {   
							"sip_event": { "type": "string" },
							"sip_field": { "type": "string" } 
						},
						"required": [ "sip_event" ]
					}
				]
			},
			"hop_count": {"type": "integer"}
		},
		"required": [ "sip_fields" ]
        }
    },
    "required": ["event_name", "event_data"]
})";

const char* InstanceActivationSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
			"event_name": {"type": "string","enum": ["request_activation"]},
			"event_data": {"type": "object",
			"properties": {
			  "activate": {"type": "boolean", "enum" : [true,false] }
			},
		  "required": ["activate"]
        }
    },
    "required": ["event_name", "event_data"]
})";

const char* SendDTMFSchema = R"(
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
                "digits": {"type": "string", "minLength": 1}
            },
            "required": ["call_uuid", "digits"]
        }
    },
    "required": ["event_name", "event_data"]
})";

}
