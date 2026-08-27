#pragma once

namespace sched
{

inline constexpr const char* C_ConfFileSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
      "dialer_app": {"type": "string", "minLength": 2},
      "enable": {"type": "boolean", "enum" : [true,false] },
      "strict_limits": {"type": "boolean", "enum" : [true,false] },
      "short_delay": {"type": "integer", "minimum": 2},
      "long_delay": {"type": "integer", "minimum": 2},
      "max_number_buffer_size": {"type": "integer", "minimum": 100, "maximum": 10000},
      "cps_percent": {"type": "number", "maximum": 1.0},
      "dial_timeout": {"type": "integer", "minimum": 5, "maximum": 60},
      "working_hours": {"type": "string", "pattern": "^[0-9]{4}-[0-9]{4}$"}
    },
    "required": ["dialer_app", "working_hours"]
})";

inline constexpr const char* C_QueueCallSchema = R"(
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

inline constexpr const char* C_CreateNumberMaskSessionSchema = R"(
{
	"$schema": "http://json-schema.org/draft-07/schema#",
	"type": "object",
	"properties": {
		"event_name": {"type": "string", "enum": ["request_create_number_mask_session"] },
		"event_data": {"type": "object",
		"properties" : {
			"campaign": {"type": "string", "minLength": 2, "maxLength": 60},
			"tenant_id": {"type": "string" , "minLength": 2, "maxLength": 20},
			"participants": { "type": "array","items": {"type": "string", "minLength": 2, "maxLength": 25}, "minItems": 2, "maxItems": 2},
			"session_expiry_seconds": {"type": "integer", "default": 3600}
		},
		"required": ["campaign", "tenant_id", "participants", "session_expiry_seconds"] 
		}
	},
	"required": [ "event_name", "event_data"]
})";

inline constexpr const char* C_DeleteNumberMaskSessionSchema = R"(
{
	"$schema": "http://json-schema.org/draft-07/schema#",
	"type": "object",
	"properties": {
		"event_name": {"type": "string", "enum": ["request_delete_number_mask_session"] },
		"event_data": {"type": "object",
		"properties" : {
			"mask_number": {"type": "string", "minLength": 3, "maxLength": 25},
			"any_one_participant": {"type": "string", "minLength": 3, "maxLength": 25}
		},
		"required": ["mask_number","any_one_participant"] 
		}
	},
	"required": [ "event_name", "event_data"]
})";

inline constexpr const char* C_AddSipGatewaySchema = R"(
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
			"dialer_ip_list": { "type": "array","items": {"type": "string"}},
			"did_prefix": {"type": "string", "minLength": 2, "maxLength": 15},
			"did_range": { "type": "array", "minItems": 1, "uniqueItems": true,
							"items": {"type": "string","pattern": "^[0-9]{3,10}-[0-9]{3,10}$"}}
		},
		"required": [ "name", "params", "capacity", "cps", "enable","dialer_ip_list" ]
		}
	},
	"required": [ "event_name", "event_data"]
})";

inline constexpr const char* C_GetSipGatewayListSchema = R"(
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

inline constexpr const char* C_ManageSipGatewaySchema = R"(
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

inline constexpr const char* C_AddCampaignSchema = R"(
{
	"$schema": "http://json-schema.org/draft-07/schema#",
	"type": "object",
	"properties": {
		"event_name": {"type": "string", "enum": ["request_add_campaign"] },
		"event_data": {"type": "object",
		"properties": { 
			"name": {"type": "string", "minLength": 2, "maxLength": 55},
			"tenant_id": {"type": "string" , "minLength": 2, "maxLength": 20},
			"active": {"type": "boolean", "enum" : [true,false] },
			"campaign_type": {"type": "string", "enum" : ["bot","pred","prog","preview"] },
			"working_hours": {"type": "string", "pattern": "^[0-9]{4}-[0-9]{4}$"},
			"max_limit": {"type": "integer" }, 
			"gateways": { "type": "array",
			"items": [{"type": "object",
			"properties": { "name": {"type": "string" },
							"did_range": { "type": "array", "minItems": 1, "uniqueItems": true,
									"items": {"type": "string","pattern": "^[0-9]{3,10}-[0-9]{3,10}$"}}
							},
							"required": ["name"]}
							]}
		},
		"required": ["name","tenant_id","campaign_type","max_limit","gateways"]
		}
	},
	"required": [ "event_name", "event_data"]
})";

inline constexpr const char* C_ManageCampaignSchema = R"(
{
	"$schema": "http://json-schema.org/draft-07/schema#",
	"type": "object",
	"properties": {
		"event_name": {"type": "string", "enum": ["request_manage_campaign"] },
		"event_data": {"type": "object",
		"properties": {
			"name": {"type": "string", "minLength": 2, "maxLength": 55},
			"tenant_id": {"type": "string" , "minLength": 2, "maxLength": 20},
			"active": {"type": "boolean", "enum" : [true,false] },
			"working_hours": {"type": "string", "pattern": "^[0-9]{4}-[0-9]{4}$"},
			"max_limit": {"type": "integer" } 
		},
		"oneOf": [{"required": ["active"]},{"required": ["max_limit"]},{"required": ["working_hours"]}],
		"required": [ "name","tenant_id"]
		}
	},
	"required": [ "event_name", "event_data"]
})";

inline constexpr const char* C_DeleteCampaignSchema = R"(
{
	"$schema": "http://json-schema.org/draft-07/schema#",
	"type": "object",
	"properties": {
		"event_name": {"type": "string", "enum": ["request_delete_campaign"] },
		"event_data": {"type": "object",
		"properties": {
			"name": {"type": "string", "minLength": 2, "maxLength": 55},
			"tenant_id": {"type": "string" , "minLength": 2, "maxLength": 20}
		},
		"required": [ "name","tenant_id"]
		}
	},
	"required": [ "event_name", "event_data"]
})";

inline constexpr const char* C_InstanceActivationSchema = R"(
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

inline constexpr const char* C_IraGetCampaignStatsSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
      "event_name": {"type": "string", "enum": ["get_campaign_stats"] },
		"event_data": {"type": "object",
		"properties": {
			"campaign": {"type": "string"},
			"tenant_id": {"type": "string" , "minLength": 2, "maxLength": 20}
			},
			"required": ["campaign","tenant_id"]		
		}
	},
    "required": [ "event_name" ]
})";

inline constexpr const char* C_IraGetCampaignSizeSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
      "event_name": {"type": "string", "enum": ["get_campaign_size"] },
		"event_data": {"type": "object",
		"properties": {
			"campaign": {"type": "string"},
			"tenant_id": {"type": "string" , "minLength": 2, "maxLength": 20}
			},
			"required": [ "campaign","tenant_id"]		
		}
	},
    "required": [ "event_name" ]
})";

inline constexpr const char* C_IraSetCampaignParamsSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
      "event_name": {"type": "string", "enum": ["set_campaign_params"] },
		"event_data": {"type": "object",
			"properties": {
				"max_number_buffer_size": {"type": "integer", "minimum": 100, "maximum": 10000},
				"short_delay": {"type": "integer", "minimum": 5, "maximum": 10},
				"long_delay": {"type": "integer", "minimum": 20, "maximum": 100},
				"cps_percent": {"type": "number", "minimum": 0.1, "maximum": 1.0},
				"enable_firing_calls": {"type": "boolean", "enum" : [true,false] },
				"strict_limits": {"type": "boolean", "enum" : [true,false] },
				"dial_timeout": {"type": "integer", "minimum": 10, "maximum": 100},
				"working_hours": {"type": "string", "pattern": "^[0-9]{4}-[0-9]{4}$"}
			}
		}
    },
    "required": [ "event_name", "event_data"]
})";

inline constexpr const char* C_IraGetCampaignParamsSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
      "event_name": {"type": "string", "enum": ["get_campaign_params"] }
    },
    "required": [ "event_name", "event_data"]
})";

inline constexpr const char* C_IraRemoveCallsFromCampaignSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
      "event_name": {"type": "string", "enum": ["remove_calls_from_campaign"] },
		"event_data": {"type": "object",
			"properties": {
				"campaign": {"type": "string", "minLength": 1 },
				"tenant_id": {"type": "string" , "minLength": 2, "maxLength": 20}
			},
			"required": ["campaign","tenant_id"]		
		}
    },
    "required": [ "event_name", "event_data"]
})";

inline constexpr const char* C_IraDialPredictiveSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
      "event_name": {"type": "string", "enum": ["request_predictive_dial"] },
		"event_data": {"type": "object",
			"properties": {
				"campaign": {"type": "string", "minLength": 1 },
				"tenant_id": {"type": "string" , "minLength": 2, "maxLength": 20},
				"dial_schedule": { "type": "array","items": {"type": "integer"}}
			},
			"required": ["campaign","tenant_id", "dial_schedule"]		
		}
    },
    "required": [ "event_name", "event_data"]
})";

inline constexpr const char* C_IraDialProgressiveSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
      "event_name": {"type": "string", "enum": ["request_progressive_dial"] },
		"event_data": {"type": "object",
			"properties": {
				"campaign": {"type": "string", "minLength": 1 },
				"tenant_id": {"type": "string" , "minLength": 2, "maxLength": 20},
				"dial_count": {"type": "integer", "minimum": 1}
			},
			"required": ["campaign","tenant_id", "dial_count"]		
		}
    },
    "required": [ "event_name", "event_data"]
})";

}
