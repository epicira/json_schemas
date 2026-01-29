const char* ConfFileSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
		"websocket_app": {"type": "string", "minLength": 1, "maxLength": 60},
		"websocket_port": {"type": "integer"},
		"encode_useraudio": {"type": "boolean", "enum" : [true,false], "default": true },
		"log_audio": {"type": "boolean", "enum" : [true,false], "default": false },
		"vad": {"type": "string", "enum" : ["no","dsp","onnx"] },
		"streaming_useraudio": {"type": "boolean", "enum" : [true,false], "default": true },
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
		"record": {"type": "string", "enum" : ["none","mp3","wav"] },
		"mp3_quality": {"type": "integer", "minimum": 0, "maximum": 9},
		"induce_error": {"type": "boolean", "enum" : [true,false] },
		"bot_audio_mode": {"type": "string", "enum" : ["stream","blocks"] },
		"bot_response_mode": {"type": "string", "enum" : ["periodic","sequence"] },
		"audio_interval" : {"type": "integer", "minimum": 1},
		"audio_filename": {"type": "string", "minLength": 5, "maxLength": 250},
		"bot_inactivity_limit" : {"type": "integer"},
		"result_subject": {"type": "string"},
		"siprec_stream_leg": {"type": "string", "enum" : ["NONE","ALEG","BLEG","BOTH"] },
		"background_audio": {"type": "string"},
		"mix_factor": {"type": "number", "minimum": 0, "maximum": 1},
		"request_queue": {"type": "string"}
	},
	"required": ["websocket_port","vad","siprec_stream_leg"]
})";

