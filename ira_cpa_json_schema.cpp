const char* SetCpaConfigSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
		"config_name": {"type": "string" },
		"tenant_id": {"type": "string" },
		"analysis": {"type": "string", "enum":["amd","eamd"]},
		"min_ambient_energy": {"type": "integer", "minimum": 100},
		"energy_lwm": {"type": "integer", "minimum": 100},
		"energy_hwm": {"type": "integer", "minimum": 4000},
		"initial_silence_ignore": {"type": "integer", "minimum": 0, "maximum": 5000},
		"sensitivity": {"type": "integer", "minimum": 2, "maximum": 5},
		"silence_detect_limit": {"type": "integer", "minimum": 1000, "maximum": 10000},
		"beep_to_silence_gap": {"type": "integer", "minimum": 0, "maximum": 10000},
		"tones": {"type": "object"},
		"log_voice": {"type": "boolean", "enum" : [true,false] },
		"log_rtp_history": {"type": "boolean", "enum" : [true,false] },
		"break_events": {"type": "string"},
		"amd_time_limit": {"type": "integer", "minimum": 1000, "maximum": 3000},
		"frequency_count": {"type": "integer", "minimum": 50, "maximum": 200},
		"minimum_frequency": {"type": "integer", "minimum": 50, "maximum": 800},
		"maximum_frequency": {"type": "integer", "minimum": 1000, "maximum": 6400},
		"eamd_silence": {"type": "integer", "minimum": 600, "maximum": 1600},
		"ar_silence_streak": {"type": "integer", "minimum": 400, "maximum": 1200},
		"amplitude_threshold": {"type": "integer", "minimum": 5000, "maximum": 100000},
		"suppress_spikes": {"type": "boolean", "enum" : [true,false] },
		"detect_dtmf": {"type": "boolean", "enum" : [true,false] },
		"beep_is_am": {"type": "boolean", "enum" : [true,false] },
		"total_timeout": {"type": "integer", "minimum": 10000}
    },
    "required": [ "config_name", "tenant_id", "analysis"]
})";

const char* SelectConfigSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
      "request_name": {"type": "string", "enum":["AMD","amd","set_cpa_params"]},
      "config_name": {"type": "string", "minLength": 1 },
      "tenant_id": {"type": "string", "minLength": 2 },
      "sampling_rate": {"type": "integer", "enum":[8000,16000]},
      "pod_id": {"type": "string"},
      "call_uuid": {"type": "string"}
    },
    "required": [ "config_name", "tenant_id"]
})";

const char* DeleteCpaConfigSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
      "config_name": {"type": "string" },
      "tenant_id": {"type": "string" }
    },
  "required": [ "config_name", "tenant_id" ]
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
      "record_directory": {"type": "string", "minLength": 2},
      "http_proxy_server": {"type": "string", "minLength": 2},
	  "ws_port": {"type": "integer", "minimum": 2000 },
	  "wss_port": {"type": "integer", "minimum": 2000 },
	  "api_http_port": {"type": "integer", "minimum": 2000 },
      "test_mode": {"type": "boolean", "enum": [true,false] },
      "request_subject": {"type": "string", "minLength": 5},
      "cpa_params": {
      "type": "array",
      "items": [
		{
            "type": "object",
			"properties": {
				"config_name": {"type": "string" },
				"tenant_id": {"type": "string" },
				"analysis": {"type": "string", "enum":["amd","eamd"]},
				"min_ambient_energy": {"type": "integer", "minimum": 100},
				"energy_lwm": {"type": "integer", "minimum": 100},
				"energy_hwm": {"type": "integer", "minimum": 4000},
				"initial_silence_ignore": {"type": "integer", "minimum": 0, "maximum": 5000},
				"sensitivity": {"type": "integer", "minimum": 2, "maximum": 5},
				"silence_detect_limit": {"type": "integer", "minimum": 1000, "maximum": 10000},
				"beep_to_silence_gap": {"type": "integer", "minimum": 0, "maximum": 10000},
				"tones": {"type": "object"},
				"log_voice": {"type": "boolean", "enum" : [true,false] },
				"log_rtp_history": {"type": "boolean", "enum" : [true,false] },
				"break_events": {"type": "string"},
				"amd_time_limit": {"type": "integer", "minimum": 1000, "maximum": 3000},
				"frequency_count": {"type": "integer", "minimum": 50, "maximum": 200},
				"minimum_frequency": {"type": "integer", "minimum": 50, "maximum": 800},
				"maximum_frequency": {"type": "integer", "minimum": 1000, "maximum": 6400},
				"eamd_silence": {"type": "integer", "minimum": 600, "maximum": 1600},
				"ar_silence_streak": {"type": "integer", "minimum": 400, "maximum": 1200},
				"amplitude_threshold": {"type": "integer", "minimum": 5000, "maximum": 100000},
				"suppress_spikes": {"type": "boolean", "enum" : [true,false] },
				"detect_dtmf": {"type": "boolean", "enum" : [true,false] },
				"beep_is_am": {"type": "boolean", "enum" : [true,false] },
				"total_timeout": {"type": "integer", "minimum": 10000}
			},
			"required": [ "config_name", "tenant_id", "analysis"]
          }
        ]
      }
    },
	"anyOf": [{"required": ["ws_port"]},{"required": ["wss_port"]}],
    "required": ["use_self_signed_certificate"]
})";

const char* TesterConfFileSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
      "test_file_dir": {"type": "string", "minLength": 2},
	  "cpatest_inter_request_delay": {"type": "integer"},
      "request_queue": {"type": "string", "minLength": 5},
      "cpa_params": {
      "type": "array",
      "items": [
		{
            "type": "object",
			"properties": {
				"config_name": {"type": "string" },
				"tenant_id": {"type": "string" },
				"analysis": {"type": "string", "enum":["amd","eamd"]},
				"min_ambient_energy": {"type": "integer", "minimum": 100},
				"energy_lwm": {"type": "integer", "minimum": 100},
				"energy_hwm": {"type": "integer", "minimum": 4000},
				"initial_silence_ignore": {"type": "integer", "minimum": 0, "maximum": 5000},
				"sensitivity": {"type": "integer", "minimum": 2, "maximum": 5},
				"silence_detect_limit": {"type": "integer", "minimum": 1000, "maximum": 10000},
				"beep_to_silence_gap": {"type": "integer", "minimum": 0, "maximum": 10000},
				"tones": {"type": "object"},
				"log_voice": {"type": "boolean", "enum" : [true,false] },
				"log_rtp_history": {"type": "boolean", "enum" : [true,false] },
				"break_events": {"type": "string"},
				"amd_time_limit": {"type": "integer", "minimum": 1000, "maximum": 3000},
				"frequency_count": {"type": "integer", "minimum": 50, "maximum": 200},
				"minimum_frequency": {"type": "integer", "minimum": 50, "maximum": 800},
				"maximum_frequency": {"type": "integer", "minimum": 1000, "maximum": 6400},
				"eamd_silence": {"type": "integer", "minimum": 600, "maximum": 1600},
				"ar_silence_streak": {"type": "integer", "minimum": 400, "maximum": 1200},
				"amplitude_threshold": {"type": "integer", "minimum": 5000, "maximum": 100000},
				"suppress_spikes": {"type": "boolean", "enum" : [true,false] },
				"detect_dtmf": {"type": "boolean", "enum" : [true,false] },
				"beep_is_am": {"type": "boolean", "enum" : [true,false] },
				"total_timeout": {"type": "integer", "minimum": 10000}
			},
			"required": [ "config_name", "tenant_id", "analysis"]
          }
        ]
      }
    },
    "required": ["test_file_dir"]
})";
