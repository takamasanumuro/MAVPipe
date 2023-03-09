#pragma once
// MESSAGE POT_READING PACKING

#define MAVLINK_MSG_ID_POT_READING 180


typedef struct __mavlink_pot_reading_t {
 uint16_t pot_reading; /*<  Potentiometer reading*/
} mavlink_pot_reading_t;

#define MAVLINK_MSG_ID_POT_READING_LEN 2
#define MAVLINK_MSG_ID_POT_READING_MIN_LEN 2
#define MAVLINK_MSG_ID_180_LEN 2
#define MAVLINK_MSG_ID_180_MIN_LEN 2

#define MAVLINK_MSG_ID_POT_READING_CRC 170
#define MAVLINK_MSG_ID_180_CRC 170



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_POT_READING { \
    180, \
    "POT_READING", \
    1, \
    {  { "pot_reading", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_pot_reading_t, pot_reading) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_POT_READING { \
    "POT_READING", \
    1, \
    {  { "pot_reading", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_pot_reading_t, pot_reading) }, \
         } \
}
#endif

/**
 * @brief Pack a pot_reading message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param pot_reading  Potentiometer reading
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pot_reading_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t pot_reading)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_POT_READING_LEN];
    _mav_put_uint16_t(buf, 0, pot_reading);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_POT_READING_LEN);
#else
    mavlink_pot_reading_t packet;
    packet.pot_reading = pot_reading;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_POT_READING_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_POT_READING;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_POT_READING_MIN_LEN, MAVLINK_MSG_ID_POT_READING_LEN, MAVLINK_MSG_ID_POT_READING_CRC);
}

/**
 * @brief Pack a pot_reading message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param pot_reading  Potentiometer reading
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pot_reading_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t pot_reading)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_POT_READING_LEN];
    _mav_put_uint16_t(buf, 0, pot_reading);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_POT_READING_LEN);
#else
    mavlink_pot_reading_t packet;
    packet.pot_reading = pot_reading;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_POT_READING_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_POT_READING;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_POT_READING_MIN_LEN, MAVLINK_MSG_ID_POT_READING_LEN, MAVLINK_MSG_ID_POT_READING_CRC);
}

/**
 * @brief Encode a pot_reading struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param pot_reading C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pot_reading_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_pot_reading_t* pot_reading)
{
    return mavlink_msg_pot_reading_pack(system_id, component_id, msg, pot_reading->pot_reading);
}

/**
 * @brief Encode a pot_reading struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param pot_reading C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pot_reading_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_pot_reading_t* pot_reading)
{
    return mavlink_msg_pot_reading_pack_chan(system_id, component_id, chan, msg, pot_reading->pot_reading);
}

/**
 * @brief Send a pot_reading message
 * @param chan MAVLink channel to send the message
 *
 * @param pot_reading  Potentiometer reading
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_pot_reading_send(mavlink_channel_t chan, uint16_t pot_reading)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_POT_READING_LEN];
    _mav_put_uint16_t(buf, 0, pot_reading);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POT_READING, buf, MAVLINK_MSG_ID_POT_READING_MIN_LEN, MAVLINK_MSG_ID_POT_READING_LEN, MAVLINK_MSG_ID_POT_READING_CRC);
#else
    mavlink_pot_reading_t packet;
    packet.pot_reading = pot_reading;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POT_READING, (const char *)&packet, MAVLINK_MSG_ID_POT_READING_MIN_LEN, MAVLINK_MSG_ID_POT_READING_LEN, MAVLINK_MSG_ID_POT_READING_CRC);
#endif
}

/**
 * @brief Send a pot_reading message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_pot_reading_send_struct(mavlink_channel_t chan, const mavlink_pot_reading_t* pot_reading)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_pot_reading_send(chan, pot_reading->pot_reading);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POT_READING, (const char *)pot_reading, MAVLINK_MSG_ID_POT_READING_MIN_LEN, MAVLINK_MSG_ID_POT_READING_LEN, MAVLINK_MSG_ID_POT_READING_CRC);
#endif
}

#if MAVLINK_MSG_ID_POT_READING_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_pot_reading_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t pot_reading)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, pot_reading);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POT_READING, buf, MAVLINK_MSG_ID_POT_READING_MIN_LEN, MAVLINK_MSG_ID_POT_READING_LEN, MAVLINK_MSG_ID_POT_READING_CRC);
#else
    mavlink_pot_reading_t *packet = (mavlink_pot_reading_t *)msgbuf;
    packet->pot_reading = pot_reading;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POT_READING, (const char *)packet, MAVLINK_MSG_ID_POT_READING_MIN_LEN, MAVLINK_MSG_ID_POT_READING_LEN, MAVLINK_MSG_ID_POT_READING_CRC);
#endif
}
#endif

#endif

// MESSAGE POT_READING UNPACKING


/**
 * @brief Get field pot_reading from pot_reading message
 *
 * @return  Potentiometer reading
 */
static inline uint16_t mavlink_msg_pot_reading_get_pot_reading(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Decode a pot_reading message into a struct
 *
 * @param msg The message to decode
 * @param pot_reading C-struct to decode the message contents into
 */
static inline void mavlink_msg_pot_reading_decode(const mavlink_message_t* msg, mavlink_pot_reading_t* pot_reading)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    pot_reading->pot_reading = mavlink_msg_pot_reading_get_pot_reading(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_POT_READING_LEN? msg->len : MAVLINK_MSG_ID_POT_READING_LEN;
        memset(pot_reading, 0, MAVLINK_MSG_ID_POT_READING_LEN);
    memcpy(pot_reading, _MAV_PAYLOAD(msg), len);
#endif
}
