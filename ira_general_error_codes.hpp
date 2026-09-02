#pragma once

#include <utility>

namespace iraerror 
{
    inline constexpr std::pair<int, const char* const> C_Success = { 0, "OK" };
    inline constexpr std::pair<int, const char* const> C_ErrorWhileExecutingRequest = { 98, "Error while executing request" };
    inline constexpr std::pair<int, const char* const> C_TdbSqlError = { 99, "TDB SQL error" };
    inline constexpr std::pair<int, const char* const> C_CantPickUpCpaConfiguration = {100, "Can't pick up CPA configuration. This happens if the API can’t find a matching CPA configuration for the call."};
    inline constexpr std::pair<int, const char* const> C_CouldNotInitializeAnalyser = {101, "Could not initialize the analyser specified in the CPA configuration"};
    inline constexpr std::pair<int, const char* const> C_CpaStreamInitializationFailed = {102, "CPA/Stream initialization failed! This happens if RTP listener cannot be started"};
    inline constexpr std::pair<int, const char* const> C_FileNotFound = {103, "File specified for playing was not found" };
    inline constexpr std::pair<int, const char* const> C_FilePlayInterrupted = {104, "File play was interrupted" };
    inline constexpr std::pair<int, const char* const> C_CallDisconnectedWhilePlaying = {105, "Call disconnected while play was playing" };
    inline constexpr std::pair<int, const char* const> C_ErrorMessageFromMediaHandler = {106, "Error message returned by the media handler while playing a message" };
    inline constexpr std::pair<int, const char* const> C_CallUuidDoesNotExist = {107, "The call_uuid mentioned in the API doesn’t exist."};
    inline constexpr std::pair<int, const char* const> C_CallUuidDoesNotExistAnymore = {108, "The call_uuid mentioned in the API doesn’t exist anymore."};
    inline constexpr std::pair<int, const char* const> C_TenantHasUsedUpAllLicenses = { 109, "Tenant has used up all the available licenses" };
    inline constexpr std::pair<int, const char* const> C_AllLicensesHaveExpired = {110, "All licenses have expired."};
    inline constexpr std::pair<int, const char* const> C_TenantDoesNotHaveLicensesInstalled = {111, "Tenant doesn't have any licenses installed."};
    inline constexpr std::pair<int, const char* const> C_UnableToUseLicenses = {112, "Unable to use the licenses."};
    inline constexpr std::pair<int, const char* const> C_UnknownErrorAcquiringLicense = {113, "Unknown error while trying to acquire license."};
    inline constexpr std::pair<int, const char* const> C_CallDialingFailed = {114, "Call dialing failed. Check status for more details."};
    inline constexpr std::pair<int, const char* const> C_CallFailedToOriginate = {115, "Call failed to originate, could be a throttling problem."};
    inline constexpr std::pair<int, const char* const> C_RecordRequestedNotFound = { 116, "Record requested not found." };
    inline constexpr std::pair<int, const char* const> C_CallInConferenceCantAcceptDtmf = { 117, "Call is in the conference, can't accept the DTMF." };
    inline constexpr std::pair<int, const char* const> C_BridgingBrandNewConferenceFailed = { 118, "Bridging into a brand new conference in the same dialer failed." };
    inline constexpr std::pair<int, const char* const> C_BridgingExistingConferenceFailed = { 119, "Bridging into an existing conference in the same dialer failed." };
    inline constexpr std::pair<int, const char* const> C_BridgingConferenceAnotherDialerFailed = { 120, "Bridging into the conference in another dialer failed." };
    inline constexpr std::pair<int, const char* const> C_FailedToMoveCurrentConferenceBeforeBridging = { 121, "Failed to move of the current conference before bridging" };
    inline constexpr std::pair<int, const char* const> C_FailedToBridgeAnotherDialer = { 122, "Failed to bridge into another dialer after moving out of current conference" };
    inline constexpr std::pair<int, const char* const> C_CallParkFailedAlreadyParked = { 123, "Call Park failed since the call is already parked" };
    inline constexpr std::pair<int, const char* const> C_FailedToParkCall = { 124, "Failed to park the call." };
    inline constexpr std::pair<int, const char* const> C_RequestedApiOnlyCalledInConference = { 125, "The requested API can only be called while in conference." };
    inline constexpr std::pair<int, const char* const> C_RequestedActionInConferenceFailed = { 126, "The requested action in the conference failed." };
    inline constexpr std::pair<int, const char* const> C_ErrorStoppingPlay = {127, "Error stopping play."};
    inline constexpr std::pair<int, const char* const> C_InvalidRequest = {128, "Invalid request."};
    inline constexpr std::pair<int, const char* const> C_NotAbleToSetCpaConfiguration = {129, "Not able to set the CPA configuration"};
    inline constexpr std::pair<int, const char* const> C_NotAllParametersSpecified = {130, "Not all parameters specified."};
    inline constexpr std::pair<int, const char* const> C_UnableToAddNewCall = {131, "Unable to add a new call."};
    inline constexpr std::pair<int, const char* const> C_HttpsErrorUnableToSendEvent = { 132, "Https error. Unable to send event over web." };
    inline constexpr std::pair<int, const char* const> C_NoSchemaFilesFound = { 133, "No schema files found" };
    inline constexpr std::pair<int, const char* const> C_IncorrectlyFormedJsonRequest = {134, "Incorrectly formed json request"};
    inline constexpr std::pair<int, const char* const> C_RequestNotAccordingToSchema = {135, "Request is not according to the schema"};
    inline constexpr std::pair<int, const char* const> C_NullUuidsInMulticonfRequest = { 136, "Null call_uuid/conf_uuid in the multiconf request" };
    inline constexpr std::pair<int, const char* const> C_CallSpecifiedDoesNotExistOrNotAnswered = { 137, "Call specified by call_uuid doesn’t exist or not in answered state" };
    inline constexpr std::pair<int, const char* const> C_SendDtmfFailed = { 138, "Send DTMF failed" };
    inline constexpr std::pair<int, const char* const> C_NumberOfCallsExceedsCapacity = {139, "Number of calls exceeds the capacity of the dialer"};
    inline constexpr std::pair<int, const char* const> C_ErrorSettingChannelVariables = {140, "Error setting channel variables"};
    inline constexpr std::pair<int, const char* const> C_ErrorInSipGatewayConfiguration = {141, "Error in SIP gateway configuration"};
    inline constexpr std::pair<int, const char* const> C_ErrorDeletingSipGateway = {142, "Error deleting SIP gateway"};
    inline constexpr std::pair<int, const char* const> C_ErrorRetrievingSipGatewayInformation = {143, "Error retrieving SIP gateway information"};
    inline constexpr std::pair<int, const char* const> C_StreamAlreadyInitiatedForCall = {144, "Stream already initiated for the call"};
    inline constexpr std::pair<int, const char* const> C_ErrorInRecording = {145, "Error in recording"};
    inline constexpr std::pair<int, const char* const> C_NoActiveDialerInstanceAvailable = {146, "No active Dialer instance available"};
    inline constexpr std::pair<int, const char* const> C_NoInactiveDialerInstanceAvailable = {147, "No inactive Dialer instance available"};
    inline constexpr std::pair<int, const char* const> C_ErrorRetrievingCallStatistics = {148, "Error retrieving call statistics from Dialer instances"};
    inline constexpr std::pair<int, const char* const> C_ErrorInTransferringCalls = {149, "Error in transferring calls"};
    inline constexpr std::pair<int, const char* const> C_InboundCallReachedInactiveInstance = {150, "Inbound call reached an inactive instance"};
    inline constexpr std::pair<int, const char* const> C_ErrorInCampaignConfiguration = {151, "Error in campaign configuration"};
    inline constexpr std::pair<int, const char* const> C_ErrorDeletingCampaignConfiguration = {152, "Error deleting campaign configuration"};
    inline constexpr std::pair<int, const char* const> C_NotAValidCampaign = {153, "Not a valid campaign"};
    inline constexpr std::pair<int, const char* const> C_NoFreeGatewayChannelsAvailable = {154, "No free gateway channels available for campaign"};
    inline constexpr std::pair<int, const char* const> C_NoNumbersInCampaign = {155, "No numbers available to dial for campaign"};
    inline constexpr std::pair<int, const char* const> C_SipGatewayNotActiveOrConfigured = {156, "SIP gateway is either not active or not configured"};
    inline constexpr std::pair<int, const char* const> C_NotActiveCampaign = { 157, "Not a valid campaign" };
    inline constexpr std::pair<int, const char* const> C_LogicalGatewayNoActiveSipGateways = {158, "Campaign doesn't have any active SIP gateways"};
    inline constexpr std::pair<int, const char* const> C_UnableToRerouteToCorrectGateway = {159, "Unable to reroute to the correct gateway"};
    inline constexpr std::pair<int, const char* const> C_CallsBelongToDifferentDialers = {160, "Calls belong to different dialers in a merge calls request"};
    inline constexpr std::pair<int, const char* const> C_MergeCallsRequestFailed = {161, "Merge calls request has failed"};
    inline constexpr std::pair<int, const char* const> C_CpuUtilizationCrossedThreshold = {162, "CPU utilization has crossed the threshold"};
    inline constexpr std::pair<int, const char* const> C_UnableToReserveMaskedNumber = {163, "Unable to reserve a masked number"};
    inline constexpr std::pair<int, const char* const> C_NoSuchMaskedNumberIsReserved = {164, "No such masked number is reserved"};
    inline constexpr std::pair<int, const char* const> C_UnableToDeleteMaskedNumberReservation = {165, "Unable to delete a masked number reservation"};
} // namespace iraerror