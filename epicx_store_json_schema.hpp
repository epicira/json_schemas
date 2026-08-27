#pragma once

namespace EpiCXStore {
    inline constexpr const char *C_AddAgentSchema = R"({
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string"},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string"},
                "id": {"type": "string"},
                "extension": {"type": "string"}
            },
            "additionalProperties": false,
            "required": ["tenant_id", "id", "extension"]
        }
    },
    "additionalProperties": false,
    "required": ["event_name", "event_data"]
})";

inline constexpr const char *C_UpdateAgentSchema = R"({
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string"},
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
        "event_name": {"type": "string"},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string"},
                "id": {"type": "string"},
            },
            "additionalProperties": false,
            "required": ["tenant_id", "id"]
        }
    },
    "additionalProperties": false,
    "required": ["event_name", "event_data"]
})";

inline constexpr const char *C_AddQueueSchema = R"({
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string"},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string"},
                "name": {"type": "string"},
                "priority": {"type": "integer"},
                "size": {"type": "integer"},
                "strategy": {"type": "string"},
                "active": {"type": "boolean"},
                "direction": {"type": "string"},
                "acw_timeout": {"type": "integer"},
                "max_calls": {"type": "integer"},
                "abandonment_seconds": {"type": "integer"},
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
                "max_calls", "abandonment_seconds"
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
        "event_name": {"type": "string"},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string"},
                "id": {"type": "string"},
                "name": {"type": "string"},
                "priority": {"type": "integer"},
                "size": {"type": "integer"},
                "strategy": {"type": "string"},
                "active": {"type": "boolean"},
                "direction": {"type": "string"},
                "acw_timeout": {"type": "integer"},
                "max_calls": {"type": "integer"},
                "abandonment_seconds": {"type": "integer"},
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
        "event_name": {"type": "string"},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string"},
                "id": {"type": "string"},
            },
            "additionalProperties": false,
            "required": ["tenant_id", "id"]
        }
    },
    "additionalProperties": false,
    "required": ["event_name", "event_data"]
})";


inline constexpr const char *C_AddAgentQueueMapSchema = R"({
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string"},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string"},
                "agent_id": {"type": "string"},
                "queue_id": {"type": "string"}
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
        "event_name": {"type": "string"},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string"},
                "agent_id": {"type": "string"},
                "queue_id": {"type": "string"}
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
        "event_name": {"type": "string"},
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

inline constexpr const char *C_ConfigFileSchema = R"({
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
        "pg_conn_str": {"type": "string", "description": "PostgreSQL connection string"}
    },
    "required": ["pg_conn_str"]
})";
}