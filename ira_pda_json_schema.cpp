const char* GSetConfigSchema = R"(
{
	"$schema": "http://json-schema.org/draft-07/schema#",
		"type" : "object",
		"properties" : {
		"event_name": {"type": "string", "enum" : ["request_set_config"] },
			"event_data" : {"type": "object",
			"properties" : {
				"tenant_id": {"type": "string"},
				"queue_id" : {"type": "string" },
				"max_lambda" : {"type": "number", "default" : 2, "minimum" : 2},
				"aggr_factor" : {"type": "number", "default" : 2, "minimum" : 1, "maximum" : 5},
				"aggr_step" : {"type": "number", "default" : 0.05, "minimum" : 0.05, "maximum" : 2.0},
				"aggr_auto" : {"type": "boolean", "default" : true},
				"max_queue_size" : {"type": "integer", "default" : 0, "minimum" : 0},
				"idle_low_wm" : {"type": "integer", "default" : 20, "minimum" : 5, "maximum" : 60},
				"idle_high_wm" : {"type": "integer", "default" : 40, "minimum" : 10, "maximum" : 120}
			},
			"required": ["tenant_id", "queue_id"]
		}
	},
	"required": ["event_name", "event_data"]
})";

const char* GPredictSchema = R"(
{
	"$schema": "http://json-schema.org/draft-07/schema#",
		"type" : "object",
		"properties" : {
		"event_name": {"type": "string", "enum" : ["request_prediction"] },
			"event_data" : {"type": "object",
			"properties" : {
			"tenant_id": {"type": "string"},
				"queue_id" : {"type": "string" },
				"req_id" : {"type": "integer", "minimum" : 1},
				"agents_on_call" : {"type": "integer"},
				"agents_on_acw" : {"type": "integer"},
				"agents_ready" : {"type": "integer"},
				"queued_calls" : {"type": "integer"},
				"current_dial_rate" : {"type": "number"},
				"connect_rate" : {"type": "number", "minimum" : 0.02, "maximum" : 1.0},
				"avg_call_duration" : {"type": "integer"},
				"avg_call_setup_time" : {"type": "integer"},
				"avg_agent_idle_time" : {"type": "integer"},
				"avg_acw_time" : {"type": "integer"}
			},
			"required": ["tenant_id", "queue_id", "req_id",
				"agents_on_call", "agents_on_acw", "agents_ready",
				"queued_calls", "current_dial_rate", "connect_rate",
				"avg_call_duration", "avg_call_setup_time",
				"avg_agent_idle_time", "avg_acw_time"]
		}
	},
	"required": ["event_name", "event_data"]
})";