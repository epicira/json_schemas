
namespace router
{

const char* ConfFileSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
      "dialer_app": {"type": "string", "minLength": 2},
      "app_name": {"type": "string"},
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

const char* MakeCallSchema = R"(
{
	"$schema": "http://json-schema.org/draft-07/schema#",
	"type": "object",
	"properties": {
		"event_name": {"type": "string", "enum": ["request_make_call"] },
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

const char* HangupEventSchema = R"(
{
	"$schema": "http://json-schema.org/draft-07/schema#",
	"type": "object",
	"properties": {
		"event_name": {"type": "string", "enum": ["report_hangup_event"] },
		"event_data": {"type": "object",
		"properties" : {
			"call_uuid": {"type": "string", "pattern": "^[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}$"},
			"dialer_pod": {"type": "string", "minLength": 2}
		},
		"required": ["call_uuid","dialer_pod"] 
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

const char* UpdateGatewayMapSchema = R"(
{
	"$schema": "http://json-schema.org/draft-07/schema#",
	"type": "object",
	"properties": {
		"event_name": {"type": "string", "enum": ["request_update_gateway_mapping"] },
		"event_data": {"type": "object",
		"properties": {
			"gateway_name": {"type": "string", "minLength": 2},
			"dialer_ip_address": {"type": "string", "minLength": 2, "maxLength": 15},
			"dialer_pod_id": {"type": "string", "minLength": 2},
			"usage": {"type": "integer"},
			"gateway_status": {"type": "string", "minLength": 2}
		},
		"required": [ "gateway_name", "dialer_pod_id", "dialer_ip_address", "gateway_status", "usage"]
		}
	},
	"required": [ "event_name", "event_data"]
})";

const char* UpdateDialerInfoSchema = R"(
{
	"$schema": "http://json-schema.org/draft-07/schema#",
	"type": "object",
	"properties": {
		"event_name": {"type": "string", "enum": ["request_update_dialer_info"] },
		"event_data": {"type": "object",
			"properties": {
				"dialer_pod_id": {"type": "string", "minLength": 2},
				"dialer_ip_address": {"type": "string", "minLength": 2, "maxLength": 15},
				"machine_id": {"type": "string", "minLength": 2},
				"max_channels": {"type": "integer"},
				"usage": {"type": "integer"},
				"dialer_state": {"type": "integer"}
			},
			"required": [ "dialer_ip_address", "dialer_pod_id", "machine_id", "dialer_state", "max_channels", "usage"]
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
		"event_name": {"type": "string", "enum": ["request_add_campaign_name"] },
		"event_data": {"type": "object",
		"properties": { 
			"name": {"type": "string", "minLength": 2, "maxLength": 55},
			"active": {"type": "boolean", "enum" : [true,false] },
			"max_limit": {"type": "integer" }, 
			"gateways": { "type": "array",
			"items": [{"type": "object",
			"properties": { "name": {"type": "string" },
							"did_range": { "type": "array","items": [{"type": "string", "pattern": "^[0-9]{10}-[0-9]{10}$"}]}
							},
							"required": ["name"]}
							]}
		},
		"required": ["name","max_limit","gateways"]
		}
	},
	"required": [ "event_name", "event_data"]
})";

const char* ManageCampaignSchema = R"(
{
	"$schema": "http://json-schema.org/draft-07/schema#",
	"type": "object",
	"properties": {
		"event_name": {"type": "string", "enum": ["request_manage_campaign_name"] },
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
		"event_name": {"type": "string", "enum": ["request_delete_campaign_name"] },
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
}
