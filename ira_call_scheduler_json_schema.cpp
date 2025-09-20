
namespace sched
{

const char* ConfFileSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
      "dialer_app": {"type": "string", "minLength": 2},
      "enable": {"type": "boolean", "enum" : [true,false] },
      "short_delay": {"type": "integer", "minimum": 2},
      "long_delay": {"type": "integer", "minimum": 2},
      "max_total_queue_size": {"type": "integer", "minimum": 100},
      "cps_percent": {"type": "number", "maximum": 1.0},
      "dial_timeout": {"type": "integer", "minimum": 5, "maximum": 60},
      "working_hours": {"type": "string", "minLength": 5}
    },
    "required": ["dialer_app", "working_hours"]
})";

const char* QueueCallSchema = R"(
{
	"$schema": "http://json-schema.org/draft-07/schema#",
	"type": "object",
	"properties": {
		"event_name": {"type": "string", "enum": ["request_queue_call","request_make_call_now"] },
		"event_data": {"type": "object",
		"properties" : {
			"campaign": {"type": "string", "minLength": 2, "maxLength": 60},
			"call_uuid": {"type": "string", "pattern": "^[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}$"},
			"tenant_id": {"type": "string" , "minLength": 2, "maxLength": 20},
			"to_number": {"type": "string", "minLength": 3, "maxLength": 25},
			"from_number": {"type": "string", "maxLength": 25},
			"event_subject": {"type": "string", "minLength": 2, "maxLength": 50},
			"cpa_config": {"type": "string", "minLength": 0, "maxLength": 15},
			"dial_timeout": {"type": "integer", "minimum": 5},
			"channel_vars": {"type": "object"},
			"call_params": {"type": "object"},
			"conf_uuid": {"type": "string", "pattern": "^CONF-[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}$"},
			"add_to_conf": {"type": "string", "pattern": "^[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}$"},
			"join_conf": {"type": "boolean", "enum" : [true,false] }
		},
		"required": ["campaign", "to_number", "tenant_id", "event_subject"] 
		}
	},
	"required": [ "event_name", "event_data"]
})";

const char* AddSipGatewaySchema = R"(
{
	"$schema": "http://json-schema.org/draft-07/schema#",
	"type": "object",
	"properties": {
		"event_name": {"type": "string", "enum": ["request_add_sip_gateway"] },
		"event_data": {"type": "object",
		"properties": {
			"name": {"type": "string", "minLength": 2, "maxLength": 30},
			"sip_profile": {"type": "string", "minLength": 2, "maxLength": 15},
			"enable": {"type": "boolean", "enum" : [true,false] },
			"capacity": {"type": "integer", "minimum": 1, "maximum": 10000},
			"cps": {"type": "integer"},
			"params": {"type": "object" },
			"variables": {"type": "object"},
			"disable_after": {"type": "integer", "minimum": 0},
			"hop_count": {"type": "integer"},
			"dialer_ip_list": { "type": "array","items": [{"type": "string"}]},
			"did_prefix": {"type": "string", "minLength": 2, "maxLength": 15},
			"did_range": { "type": "array","items": [{"type": "string", "pattern": "^[0-9]{3,10}-[0-9]{3,10}$"}]}
		},
		"required": [ "name", "params", "capacity", "cps", "enable","dialer_ip_list" ]
		}
	},
	"required": [ "event_name", "event_data"]
})";

const char* GetSipGatewayListSchema = R"(
{
	"$schema": "http://json-schema.org/draft-07/schema#",
	"type": "object",
	"properties": {
		"event_name": {"type": "string", "enum": ["request_sip_gateway_list"] },
		"event_data": {"type": "object",
		"properties": {
			"dialer_ip": {"type": "string", "minLength": 2, "maxLength": 15}
			},
		"required": [ "dialer_ip"]
		}
	},
	"required": [ "event_name", "event_data"]
})";

const char* ManageSipGatewaySchema = R"(
{
	"$schema": "http://json-schema.org/draft-07/schema#",
	"type": "object",
	"properties": {
		"event_name": {"type": "string", "enum": ["request_manage_sip_gateway"] },
		"event_data": {"type": "object",
		"properties": {
			"name": {"type": "string", "minLength": 2, "maxLength": 30},
			"sip_profile": {"type": "string", "minLength": 2, "maxLength": 15},
			"action": {"type": "string", "enum" : ["delete","enable","disable","clear","resize"] },
			"new_size" : {"type": "integer"},
			"hop_count": {"type": "integer"}
		},
		"required": [ "name", "action"]
		}
	},
	"required": [ "event_name", "event_data"]
})";

const char* AddCampaignSchema = R"(
{
	"$schema": "http://json-schema.org/draft-07/schema#",
	"type": "object",
	"properties": {
		"event_name": {"type": "string", "enum": ["request_add_campaign"] },
		"event_data": {"type": "object",
		"properties": { 
			"name": {"type": "string", "minLength": 2, "maxLength": 55},
			"active": {"type": "boolean", "enum" : [true,false] },
			"queue_type": {"type": "string", "enum" : ["bot","pred","prog","preview"] },
			"max_limit": {"type": "integer" }, 
			"gateways": { "type": "array",
			"items": [{"type": "object",
			"properties": { "name": {"type": "string" },
							"did_range": { "type": "array","items": [{"type": "string", "pattern": "^[0-9]{3,10}-[0-9]{3,10}$"}]}
							},
							"required": ["name"]}
							]}
		},
		"required": ["name","queue_type","max_limit","gateways"]
		}
	},
	"required": [ "event_name", "event_data"]
})";

const char* ManageCampaignSchema = R"(
{
	"$schema": "http://json-schema.org/draft-07/schema#",
	"type": "object",
	"properties": {
		"event_name": {"type": "string", "enum": ["request_manage_campaign"] },
		"event_data": {"type": "object",
		"properties": {
			"name": {"type": "string", "minLength": 2, "maxLength": 55},
			"active": {"type": "boolean", "enum" : [true,false] },
			"max_limit": {"type": "integer" } 
		},
		"required": [ "name"]
		}
	},
	"required": [ "event_name", "event_data"]
})";

const char* DeleteCampaignSchema = R"(
{
	"$schema": "http://json-schema.org/draft-07/schema#",
	"type": "object",
	"properties": {
		"event_name": {"type": "string", "enum": ["request_delete_campaign"] },
		"event_data": {"type": "object",
		"properties": {
		"name": {"type": "string", "minLength": 2, "maxLength": 55}
		},
		"required": [ "name"]
		}
	},
	"required": [ "event_name", "event_data"]
})";

const char* InstanceActivationSchema = R"(
{
	"$schema": "http://json-schema.org/draft-07/schema#",
	"type": "object",
	"properties": {
		"event_name": {"type": "string", "enum": ["request_deactivate_instance","request_activate_instance","request_get_instance_data"] },
		"event_data": {"type": "object",
		"properties": {
			"event_subject": {"type": "string"},
			"key": {"type": "string", "enum" : ["pod_id", "ip_address", "machine_id", "any"] },
			"key_data": {"type": "string"},
			"password": {"type": "string"}
		},
		"required": [ "password","key" ]
		}
	},
	"required": [ "event_name", "event_data"]
})";

const char* IraGetQueueStatsSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
      "event_name": {"type": "string", "enum": ["get_campaign_stats"] },
		"event_data": {"type": "object",
		"properties": {
			"campaign": {"type": "string"}
			}
		}
	},
    "required": [ "event_name" ]
})";

const char* IraGetCampaignQueueSizeSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
      "event_name": {"type": "string", "enum": ["get_campaign_queue_size"] },
		"event_data": {"type": "object",
		"properties": {
			"campaign": {"type": "string"}
			},
		"required": [ "campaign"]		
		}
	},
    "required": [ "event_name" ]
})";

const char* IraSetQueueParamsSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
      "event_name": {"type": "string", "enum": ["set_queue_params"] },
		"event_data": {"type": "object",
			"properties": {
				"max_total_queue_size": {"type": "integer", "minimum": 1, "maximum": 200000},
				"short_delay": {"type": "integer", "minimum": 5, "maximum": 10},
				"long_delay": {"type": "integer", "minimum": 20, "maximum": 100},
				"cps_percent": {"type": "number", "minimum": 0.1, "maximum": 1.0},
				"enable_firing_calls": {"type": "boolean", "enum" : [true,false] },
				"dial_timeout": {"type": "integer", "minimum": 10, "maximum": 100},
				"working_hours": {"type": "string", "pattern": "^(?:[01]\\d|2[0-3])[0-5]\\d-(?:[01]\\d|2[0-3])[0-5]\\d$"}
			}
		}
    },
    "required": [ "event_name", "event_data"]
})";

const char* IraGetQueueParamsSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
      "event_name": {"type": "string", "enum": ["get_queue_params"] }
    },
    "required": [ "event_name", "event_data"]
})";

const char* IraRemoveCallsFromQueueSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
      "event_name": {"type": "string", "enum": ["remove_calls_from_queue"] },
		"event_data": {"type": "object",
			"properties": {
				"campaign": {"type": "string", "minLength": 1 }
			}
		}
    },
    "required": [ "event_name", "event_data"]
})";

const char* IraDialPredictiveSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
      "event_name": {"type": "string", "enum": ["request_predictive_dial"] },
		"event_data": {"type": "object",
			"properties": {
				"campaign": {"type": "string", "minLength": 1 },
				"dial_schedule": { "type": "array","items": [{"type": "integer"}]}
			},
			"required": ["campaign", "dial_schedule"]		
		}
    },
    "required": [ "event_name", "event_data"]
})";

const char* IraDialProgressiveSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
      "event_name": {"type": "string", "enum": ["request_progressive_dial"] },
		"event_data": {"type": "object",
			"properties": {
				"campaign": {"type": "string", "minLength": 1 },
				"dial_count": {"type": "integer", "minimum": 1}
			},
			"required": ["campaign", "dial_count"]		
		}
    },
    "required": [ "event_name", "event_data"]
})";

}
