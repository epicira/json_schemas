const char* BasicConfFileSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
	"cluster_id": {"type": "string", "minLength": 2, "maxLength": 30},
	"app_log_level": {"type": "string", "enum" : ["debug", "info", "warn", "err", "critical","trace"] },
	"enable_log": {"type": "boolean", "enum" : [true,false] },
	"log_days": {"type": "integer"},
	"app_detailed_log": {"type": "boolean", "enum" : [true,false] },
	"heartbeat_check_period": {"type": "integer"},
	"irawatch_subject": {"type": "string", "minLength": 5},
	"ira_license_web": {"type": "string", "minLength": 5},
	"ira_cdr_web": {"type": "string", "minLength": 5},
	"ira_http_proxy": {"type": "string", "minLength": 5},
	"ira_core_count": {"type": "integer"},
	"ira_core_thread_count": {"type": "integer"},
	"ira_tdb_thread_count": {"type": "integer"},
	"nats_conf_file": {"type": "string", "minLength": 2},
	"nats_conf": {"type": "object",
		"properties": {
			"nats_url": {"type": "string", "minLength": 5},
			"nats_public_key": {"type": "string", "minLength": 5},
			"nats_seed_key": {"type": "string", "minLength": 5},
			"sys_nats_public_key": {"type": "string", "minLength": 5},
			"sys_nats_seed_key": {"type": "string", "minLength": 5}
			},
		"required": ["nats_url", "nats_public_key", "nats_seed_key"]
		}
	},
	"oneOf": [{"required": ["nats_conf_file"]},{"required": ["nats_conf"]}],
	"required": [ "cluster_id"]
})";

const char* NatsConfFileSchema = R"(
{
"$schema": "http://json-schema.org/draft-07/schema#",
"type": "object",
"properties": {
	"nats_url": {"type": "string", "minLength": 5},
	"nats_public_key": {"type": "string", "minLength": 5},
	"nats_seed_key": {"type": "string", "minLength": 5},
	"sys_nats_public_key": {"type": "string", "minLength": 5},
	"sys_nats_seed_key": {"type": "string", "minLength": 5}
	},
"required": ["nats_url", "nats_public_key", "nats_seed_key"]
})";
