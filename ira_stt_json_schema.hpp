#pragma once


inline constexpr const char* G_ConfFileSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
	"model_directory": {"type": "string", "minLength": 2, "default": "/usr/local/epi/conf/models"},
	"http_port": {"type": "integer", "default": 8081},
	"response_inference_time": {"type": "boolean", "enum" : [true,false], "default": false },
	"max_stt_buffer_seconds": {"type": "integer", "default": 30},
	"max_stt_cores": {"type": "integer","minimum": 1, "default": 4},	// Maximum number is limited to the number of hardware threads available on the system
	"decoder": {"type": "integer", "minimum": 0, "maximum": 2, "default": 2 },
	"tenant_id": {"type": "string", "minLength": 2, "default": "default"}
	},
	"required": ["model_directory", "http_port"]
})";