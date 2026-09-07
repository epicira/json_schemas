#pragma once

namespace EpiCXStore {
inline constexpr const char *C_AddAgentSchema = R"({
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string", "enum": ["acd::request_add_agent"]},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string"},
                "id": {"type": "string"},
                "extension": {"type": "string"}
            },
            "additionalProperties": false,
            "required": ["tenant_id", "extension"]
        }
    },
    "additionalProperties": false,
    "required": ["event_name", "event_data"]
})";

inline constexpr const char *C_UpdateAgentSchema = R"({
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string", "enum": ["acd::request_update_agent"]},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string"},
                "id": {"type": "string"},
                "extension": {"type": "string"}
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
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string", "enum": ["acd::request_delete_agent"]},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string"},
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
    "$schema": "http://json-schema.org/draft-07/schema#",
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
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string", "enum": ["acd::request_add_queue"]},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string"},
                "id": {"type": "string"},
                "name": {"type": "string"},
                "priority": {"type": "integer"},
                "size": {"type": "integer"},
                "strategy": {"type": "string", "enum": ["most_skilled", "most_idle"]},
                "active": {"type": "boolean"},
                "direction": {"type": "string", "enum": ["inbound", "outbound"]},
                "acw_timeout": {"type": "integer"},
                "max_calls": {"type": "integer"},
                "open_time": {"type": "string"},
                "hold_music": {"type": "string"},
                "hold_messages": {
                    "type": "array",
                    "items": {"type": "string"}
                },
                "agent_hold_music": {"type": "string"},
                "open_message": {"type": "string"},
                "close_message": {"type": "string"},
                "whisper_tone": {"type": "string"}
            },
            "additionalProperties": false,
            "required": [
                "tenant_id", "name", "priority", "size", "strategy",
                "active", "direction", "acw_timeout",
                "max_calls"
            ]
        }
    },
    "additionalProperties": false,
    "required": ["event_name", "event_data"]
})";

inline constexpr const char *C_UpdateQueueSchema = R"({
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string", "enum": ["acd::request_update_queue"]},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string"},
                "id": {"type": "string"},
                "name": {"type": "string"},
                "priority": {"type": "integer"},
                "size": {"type": "integer"},
                "strategy": {"type": "string", "enum": ["most_skilled", "most_idle"]},
                "active": {"type": "boolean"},
                "direction": {"type": "string", "enum": ["inbound", "outbound"]},
                "acw_timeout": {"type": "integer"},
                "max_calls": {"type": "integer"},
                "open_time": {"type": "string"},
                "hold_music": {"type": "string"},
                "hold_messages": {
                    "type": "array",
                    "items": {"type": "string"}
                },
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
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string", "enum": ["acd::request_delete_queue"]},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string"},
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
    "$schema": "http://json-schema.org/draft-07/schema#",
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
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string", "enum": ["acd::request_add_agent_queue_map"]},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string"},
                "agent_id": {"type": "string"},
                "queue_id": {"type": "string"},
                "skill_level": {"type": "integer"}
            },
            "additionalProperties": false,
            "required": ["tenant_id", "agent_id", "queue_id", "skill_level"]
        }
    },
    "additionalProperties": false,
    "required": ["event_name", "event_data"]
})";

inline constexpr const char *C_UpdateAgentQueueMapSchema = R"({
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string", "enum": ["acd::request_update_agent_queue_map"]},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string"},
                "agent_id": {"type": "string"},
                "queue_id": {"type": "string"},
                "skill_level": {"type": "integer"}
            },
            "additionalProperties": false,
            "required": ["tenant_id", "agent_id", "queue_id", "skill_level"]
        }
    },
    "additionalProperties": false,
    "required": ["event_name", "event_data"]
})";

inline constexpr const char *C_DeleteAgentQueueMapSchema = R"({
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string", "enum": ["acd::request_delete_agent_queue_map"]},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string"},
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
    "$schema": "http://json-schema.org/draft-07/schema#",
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

inline constexpr const char *C_AddAgentStateSchema = R"({
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string", "enum": ["acd::request_add_agent_state"]},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string"},
                "name": {"type": "string"},
                "category": {"type": "string", enum: ["ready", "break", "acw"]}
            },
            "additionalProperties": false,
            "required": ["tenant_id", "name", "category"]
        }
    },
    "additionalProperties": false,
    "required": ["event_name", "event_data"]
})";

inline constexpr const char *C_UpdateAgentStateSchema = R"({
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string", "enum": ["acd::request_update_agent_state"]},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string"},
                "id": {"type": "string"},
                "name": {"type": "string"},
                "category": {"type": "integer", enum: ["ready", "break", "acw"]}
            },
            "minProperties": 3,
            "additionalProperties": false,
            "required": ["tenant_id", "id"]
        }
    },
    "additionalProperties": false,
    "required": ["event_name", "event_data"]
})";

inline constexpr const char *C_DeleteAgentStateSchema = R"({
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string", "enum": ["acd::request_delete_agent_state"]},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string"},
                "id": {"type": "string"}
            },
            "additionalProperties": false,
            "required": ["tenant_id", "id"]
        }
    },
    "additionalProperties": false,
    "required": ["event_name", "event_data"]
})";

inline constexpr const char* C_GetAgentStatesSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string", "enum": ["acd::request_get_agent_states"]},
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

inline constexpr const char* C_AddAudioDataSchema = R"(
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
        "tenant_id": {"type": "string"},
        "queue_id": {"type": "string"},
        "name": {"type": "string"},
        "kind": {"type": "string"}
    },
    "required": ["tenant_id", "queue_id", "name", "kind"]
)";

inline constexpr const char *C_ConfigFileSchema = R"({
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
        "pg_conn_str": {"type": "string", "description": "PostgreSQL connection string"},
        "request_emit_subject": {"type": "string", "description": "On successful request processing, the original request is emitted on this subject"}
    },
    "required": ["pg_conn_str", "request_emit_subject"]
})";
}