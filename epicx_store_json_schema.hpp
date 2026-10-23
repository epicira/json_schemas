#pragma once

namespace EpiCXStore {
inline constexpr const char *C_AddAgentSchema = R"({
    "$schema": "http://json-schema.org/draft-04/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string", "enum": ["acd::request_add_agent"]},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string", "not": {"enum": ["all"]}},
                "id": {"type": "string"},
                "extension": {"type": "string", "minLength": 1}
            },
            "additionalProperties": false,
            "required": ["tenant_id", "extension"]
        }
    },
    "additionalProperties": false,
    "required": ["event_name", "event_data"]
})";

inline constexpr const char *C_UpdateAgentSchema = R"({
    "$schema": "http://json-schema.org/draft-04/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string", "enum": ["acd::request_update_agent"]},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string", "not": {"enum": ["all"]}},
                "id": {"type": "string"},
                "extension": {"type": "string", "minLength": 1}
            },
            "additionalProperties": false,
            "minProperties": 3,
            "required": ["tenant_id", "id"]
        }
    },
    "additionalProperties": false,
    "required": ["event_name", "event_data"]
})";

inline constexpr const char *C_DeleteAgentSchema = R"({
    "$schema": "http://json-schema.org/draft-04/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string", "enum": ["acd::request_delete_agent"]},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string", "not": {"enum": ["all"]}},
                "id": {"type": "string"}
            },
            "additionalProperties": false,
            "required": ["tenant_id", "id"]
        }
    },
    "additionalProperties": false,
    "required": ["event_name", "event_data"]
})";

inline constexpr const char* C_GetAgentsSchema = R"(
{
    "$schema": "http://json-schema.org/draft-04/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string", "enum": ["acd::request_get_agents"]},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string"}
            },
            "additionalProperties": false,
            "required": ["tenant_id"]
        }
    },
    "additionalProperties": false,
    "required": ["event_name", "event_data"]
})";

inline constexpr const char *C_AddQueueSchema = R"({
    "$schema": "http://json-schema.org/draft-04/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string", "enum": ["acd::request_add_queue"]},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string", "not": {"enum": ["all"]}},
                "id": {"type": "string"},
                "name": {"type": "string"},
                "priority": {"type": "integer", "minimum": 1, "maximum": 5},
                "strategy": {"type": "string", "enum": ["most_skilled", "most_idle"]},
                "active": {"type": "boolean"},
                "direction": {"type": "string", "enum": ["inbound", "outbound"]},
                "acw_timeout": {"type": "integer", "minimum": 0, "description": "ACW timeout in seconds"},
                "working_hours": {"type": "string", "description": "value must be the ID of the working hours profile"},
                "hold_music": {"type": "string", "description": "value must be the key of the audio that is uploaded"},
                "agent_hold_music": {"type": "string"},
                "open_message": {"type": "string"},
                "close_message": {"type": "string"},
                "whisper_tone": {"type": "string"}
            },
            "additionalProperties": false,
            "required": [
                "tenant_id", "name", "priority", "strategy",
                "active", "direction", "acw_timeout"
            ]
        }
    },
    "additionalProperties": false,
    "required": ["event_name", "event_data"]
})";

inline constexpr const char *C_UpdateQueueSchema = R"({
    "$schema": "http://json-schema.org/draft-04/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string", "enum": ["acd::request_update_queue"]},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string", "not": {"enum": ["all"]}},
                "id": {"type": "string"},
                "name": {"type": "string"},
                "priority": {"type": "integer", "minimum": 1, "maximum": 5},
                "strategy": {"type": "string", "enum": ["most_skilled", "most_idle"]},
                "active": {"type": "boolean"},
                "direction": {"type": "string", "enum": ["inbound", "outbound"]},
                "acw_timeout": {"type": "integer", "minimum": 0, "description": "ACW timeout in seconds"},
                "working_hours": {"type": "string", "description": "value must be the ID of the working hours profile"},
                "hold_music": {"type": "string", "description": "value must be the key of the audio that is uploaded"},
                "agent_hold_music": {"type": "string"},
                "open_message": {"type": "string"},
                "close_message": {"type": "string"},
                "whisper_tone": {"type": "string"}
            },
            "additionalProperties": false,
            "minProperties": 3,
            "required": ["tenant_id", "id"]
        }
    },
    "additionalProperties": false,
    "required": ["event_name", "event_data"]
})";

inline constexpr const char *C_DeleteQueueSchema = R"({
    "$schema": "http://json-schema.org/draft-04/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string", "enum": ["acd::request_delete_queue"]},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string", "not": {"enum": ["all"]}},
                "id": {"type": "string"}
            },
            "additionalProperties": false,
            "required": ["tenant_id", "id"]
        }
    },
    "additionalProperties": false,
    "required": ["event_name", "event_data"]
})";

inline constexpr const char* C_GetQueuesSchema = R"({
    "$schema": "http://json-schema.org/draft-04/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string", "enum": ["acd::request_get_queues"]},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string"}
            },
            "additionalProperties": false,
            "required": ["tenant_id"]
        }
    },
    "additionalProperties": false,
    "required": ["event_name", "event_data"]
})";

inline constexpr const char *C_AddAgentQueueMapSchema = R"({
    "$schema": "http://json-schema.org/draft-04/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string", "enum": ["acd::request_add_agent_queue_map"]},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string", "not": {"enum": ["all"]}},
                "agent_id": {"type": "string"},
                "queue_id": {"type": "string"},
                "skill_level": {"type": "integer", "minimum": 1, "maximum": 5}
            },
            "additionalProperties": false,
            "required": ["tenant_id", "agent_id", "queue_id", "skill_level"]
        }
    },
    "additionalProperties": false,
    "required": ["event_name", "event_data"]
})";

inline constexpr const char *C_UpdateAgentQueueMapSchema = R"({
    "$schema": "http://json-schema.org/draft-04/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string", "enum": ["acd::request_update_agent_queue_map"]},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string", "not": {"enum": ["all"]}},
                "agent_id": {"type": "string"},
                "queue_id": {"type": "string"},
                "skill_level": {"type": "integer", "minimum": 1, "maximum": 5}
            },
            "additionalProperties": false,
            "required": ["tenant_id", "agent_id", "queue_id", "skill_level"]
        }
    },
    "additionalProperties": false,
    "required": ["event_name", "event_data"]
})";

inline constexpr const char *C_DeleteAgentQueueMapSchema = R"({
    "$schema": "http://json-schema.org/draft-04/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string", "enum": ["acd::request_delete_agent_queue_map"]},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string", "not": {"enum": ["all"]}},
                "agent_id": {"type": "string"},
                "queue_id": {"type": "string"}
            },
            "additionalProperties": false,
            "required": ["tenant_id", "agent_id", "queue_id"]
        }
    },
    "additionalProperties": false,
    "required": ["event_name", "event_data"]
})";

inline constexpr const char* C_GetAgentQueueMapsSchema = R"({
    "$schema": "http://json-schema.org/draft-04/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string", "enum": ["acd::request_get_agent_queue_maps"]},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string"}
            },
            "additionalProperties": false,
            "required": ["tenant_id"]
        }
    },
    "additionalProperties": false,
    "required": ["event_name", "event_data"]
})";

inline constexpr const char *C_AddAgentBreakStateSchema = R"({
    "$schema": "http://json-schema.org/draft-04/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string", "enum": ["acd::request_add_agent_break_state"]},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string", "not": {"enum": ["all"]}},
                "name": {"type": "string", "minLength": 1},
                "type": {"type": "string", "minLength": 1, "default": "custom"}
            },
            "additionalProperties": false,
            "required": ["tenant_id", "name"]
        }
    },
    "additionalProperties": false,
    "required": ["event_name", "event_data"]
})";

inline constexpr const char *C_UpdateAgentBreakStateSchema = R"({
    "$schema": "http://json-schema.org/draft-04/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string", "enum": ["acd::request_update_agent_break_state"]},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string", "not": {"enum": ["all"]}},
                "id": {"type": "string"},
                "name": {"type": "string", "minLength": 1},
                "type": {"type": "string", "minLength": 1}
            },
            "minProperties": 3,
            "additionalProperties": false,
            "required": ["tenant_id", "id"]
        }
    },
    "additionalProperties": false,
    "required": ["event_name", "event_data"]
})";

inline constexpr const char *C_DeleteAgentBreakStateSchema = R"({
    "$schema": "http://json-schema.org/draft-04/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string", "enum": ["acd::request_delete_agent_break_state"]},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string", "not": {"enum": ["all"]}},
                "id": {"type": "string"}
            },
            "additionalProperties": false,
            "required": ["tenant_id", "id"]
        }
    },
    "additionalProperties": false,
    "required": ["event_name", "event_data"]
})";

inline constexpr const char* C_GetAgentBreakStatesSchema = R"(
{
    "$schema": "http://json-schema.org/draft-04/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string", "enum": ["acd::request_get_agent_break_states"]},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string"}
            },
            "additionalProperties": false,
            "required": ["tenant_id"]
        }
    },
    "additionalProperties": false,
    "required": ["event_name", "event_data"]
})";

inline constexpr const char *C_ConfigFileSchema = R"({
    "$schema": "http://json-schema.org/draft-04/schema#",
    "type": "object",
    "properties": {
        "pg_conn_str": {"type": "string", "description": "PostgreSQL connection string"},
        "request_emit_subject": {"type": "string", "description": "On successful request processing, the original request is emitted on this subject"}
    },
    "required": ["pg_conn_str", "request_emit_subject"]
})";

inline constexpr const char* C_GetAudioMetadataSchema = R"({
    "$schema": "http://json-schema.org/draft-04/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string", "enum": ["acd::request_get_audio_metadata"]},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string"}
            },
            "additionalProperties": false,
            "required": ["tenant_id"]
        }
    },
    "additionalProperties": false,
    "required": ["event_name", "event_data"]
})";

inline constexpr const char* C_GetExtensionsSchema = R"(
{
    "$schema": "http://json-schema.org/draft-04/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string", "enum": ["acd::request_get_extensions"]},
        "event_data": {"type": "string"}
    },
    "additionalProperties": false,
    "required": ["event_name", "event_data"]
})";

inline constexpr const char* C_AddWorkingHoursSchema = R"(
{
    "$schema": "http://json-schema.org/draft-04/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string", "enum": ["acd::request_add_working_hours"]},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string", "not": {"enum": ["all"]}},
                "name": {"type": "string"},
                "timezone": {"type": "string", "description": "IANA timezone identifier"},
                "schedule": {
                    "type": "object",
                    "properties": {
                        "sunday": { "$ref": "#/definitions/intervals" },
                        "monday": { "$ref": "#/definitions/intervals" },
                        "tuesday": { "$ref": "#/definitions/intervals" },
                        "wednesday": { "$ref": "#/definitions/intervals" },
                        "thursday": { "$ref": "#/definitions/intervals" },
                        "friday": { "$ref": "#/definitions/intervals" },
                        "saturday": { "$ref": "#/definitions/intervals" }
                    },
                    "additionalProperties": false,
                    "required": ["sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"]
                }
            },
            "additionalProperties": false,
            "required": ["tenant_id", "name", "timezone", "schedule"]
        }
    },
    "additionalProperties": false,
    "required": ["event_name", "event_data"],
    "definitions": {
        "time": {
            "type": "string",
            "pattern": "^([01][0-9]|2[0-3]):[0-5][0-9]$"
        },
        "interval": {
            "type": "object",
            "properties": {
                "start": {"$ref": "#/definitions/time"},
                "end": {"$ref": "#/definitions/time"}
            },
            "additionalProperties": false,
            "required": ["start", "end"]
        },
        "intervals": {
            "type": "array",
            "items": {"$ref": "#/definitions/interval"}
        }
    }
}
)";

inline constexpr const char* C_UpdateWorkingHoursSchema = R"(
{
    "$schema": "http://json-schema.org/draft-04/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string", "enum": ["acd::request_update_working_hours"]},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string", "not": {"enum": ["all"]}},
                "id": {"type": "string"},
                "name": {"type": "string"},
                "timezone": {"type": "string", "description": "IANA timezone identifier"},
                "schedule": {
                    "type": "object",
                    "properties": {
                        "sunday": { "$ref": "#/definitions/intervals" },
                        "monday": { "$ref": "#/definitions/intervals" },
                        "tuesday": { "$ref": "#/definitions/intervals" },
                        "wednesday": { "$ref": "#/definitions/intervals" },
                        "thursday": { "$ref": "#/definitions/intervals" },
                        "friday": { "$ref": "#/definitions/intervals" },
                        "saturday": { "$ref": "#/definitions/intervals" }
                    },
                    "additionalProperties": false,
                    "required": ["sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"]
                }
            },
            "additionalProperties": false,
            "required": ["tenant_id", "id", "name", "timezone", "schedule"]
        }
    },
    "additionalProperties": false,
    "required": ["event_name", "event_data"],
    "definitions": {
        "time": {
            "type": "string",
            "pattern": "^([01][0-9]|2[0-3]):[0-5][0-9]$"
        },
        "interval": {
            "type": "object",
            "properties": {
                "start": {"$ref": "#/definitions/time"},
                "end": {"$ref": "#/definitions/time"}
            },
            "additionalProperties": false,
            "required": ["start", "end"]
        },
        "intervals": {
            "type": "array",
            "items": {"$ref": "#/definitions/interval"}
        }
    }
}
)";

inline constexpr const char *C_DeleteWorkingHoursSchema = R"({
    "$schema": "http://json-schema.org/draft-04/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string", "enum": ["acd::request_delete_working_hours"]},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string", "not": {"enum": ["all"]}},
                "id": {"type": "string"}
            },
            "additionalProperties": false,
            "required": ["tenant_id", "id"]
        }
    },
    "additionalProperties": false,
    "required": ["event_name", "event_data"]
})";

inline constexpr const char* C_GetWorkingHoursSchema = R"({
    "$schema": "http://json-schema.org/draft-04/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string", "enum": ["acd::request_get_working_hours"]},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string"}
            },
            "additionalProperties": false,
            "required": ["tenant_id"]
        }
    },
    "additionalProperties": false,
    "required": ["event_name", "event_data"]
})";
}

