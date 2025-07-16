const char* ConfFileSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
		"websocket_app": {"type": "string", "minLength": 1, "maxLength": 60},
		"websocket_port": {"type": "integer"},
		"pstn_audio_mode": {"type": "string", "enum" : ["stream","vad"] },
		"speech_threshold" : {"type": "integer"},
		"silence_threshold" : {"type": "integer", "minimum": 1, "maximum": 20},
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
		"request_queue": {"type": "string"}
	},
	"required": ["websocket_port","pstn_audio_mode","siprec_stream_leg"]
})";

