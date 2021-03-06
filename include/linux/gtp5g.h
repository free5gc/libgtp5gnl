#ifndef _UAPI_LINUX_GTP5G_H__
#define _UAPI_LINUX_GTP5G_H__

enum gtp5g_genl_cmds {
    GTP5G_CMD_UNSPEC = 0,

    GTP5G_CMD_ADD_PDR,
    GTP5G_CMD_ADD_FAR,
    GTP5G_CMD_ADD_QER,

    GTP5G_CMD_DEL_PDR,
    GTP5G_CMD_DEL_FAR,
    GTP5G_CMD_DEL_QER,

    GTP5G_CMD_GET_PDR,
    GTP5G_CMD_GET_FAR,
    GTP5G_CMD_GET_QER,

    __GTP5G_CMD_MAX,
};

enum gtp5g_device_attrs {
    GTP5G_LINK = 1,
    GTP5G_NET_NS_FD,
};

enum gtp5g_pdr_attrs {
    /* gtp5g_device_attrs in this part */

    GTP5G_PDR_ID = 3,
    GTP5G_PDR_PRECEDENCE,
    GTP5G_PDR_PDI,
    GTP5G_OUTER_HEADER_REMOVAL,
    GTP5G_PDR_FAR_ID,

    /* Not in 3GPP spec, just used for routing */
    GTP5G_PDR_ROLE_ADDR_IPV4,

    /* Not in 3GPP spec, just used for buffering */
    GTP5G_PDR_UNIX_SOCKET_PATH,

    GTP5G_PDR_QER_ID,

    GTP5G_PDR_SEID,
    /* Add newly supported feature ON ABOVE
     * for compatability with older version of
     * free5GC's UPF or gtp5g
     * */

    __GTP5G_PDR_ATTR_MAX,
};
#define GTP5G_PDR_ATTR_MAX (__GTP5G_PDR_ATTR_MAX - 1)

/* Nest in GTP5G_PDR_PDI */
enum gtp5g_pdi_attrs {
    GTP5G_PDI_UE_ADDR_IPV4 = 1,
    GTP5G_PDI_F_TEID,
    GTP5G_PDI_SDF_FILTER,

    __GTP5G_PDI_ATTR_MAX,
};
#define GTP5G_PDI_ATTR_MAX (__GTP5G_PDI_ATTR_MAX - 1)

/* Nest in GTP5G_PDI_F_TEID */
enum gtp5g_f_teid_attrs {
    GTP5G_F_TEID_I_TEID = 1,
    GTP5G_F_TEID_GTPU_ADDR_IPV4,

    __GTP5G_F_TEID_ATTR_MAX,
};
#define GTP5G_F_TEID_ATTR_MAX (__GTP5G_F_TEID_ATTR_MAX - 1)

/* Nest in GTP5G_PDI_SDF_FILTER */
enum gtp5g_sdf_filter_attrs {
    GTP5G_SDF_FILTER_FLOW_DESCRIPTION = 1,
    GTP5G_SDF_FILTER_TOS_TRAFFIC_CLASS,
    GTP5G_SDF_FILTER_SECURITY_PARAMETER_INDEX,
    GTP5G_SDF_FILTER_FLOW_LABEL,
    GTP5G_SDF_FILTER_SDF_FILTER_ID,

    __GTP5G_SDF_FILTER_ATTR_MAX,
};
#define GTP5G_SDF_FILTER_ATTR_MAX (__GTP5G_SDF_FILTER_ATTR_MAX - 1)

/* Nest in GTP5G_SDF_FILTER_FLOW_DESCRIPTION */
enum gtp5g_flow_description_attrs {
    GTP5G_FLOW_DESCRIPTION_ACTION = 1, // Only "permit"
    GTP5G_FLOW_DESCRIPTION_DIRECTION,
    GTP5G_FLOW_DESCRIPTION_PROTOCOL,
    GTP5G_FLOW_DESCRIPTION_SRC_IPV4,
    GTP5G_FLOW_DESCRIPTION_SRC_MASK,
    GTP5G_FLOW_DESCRIPTION_DEST_IPV4,
    GTP5G_FLOW_DESCRIPTION_DEST_MASK,
    GTP5G_FLOW_DESCRIPTION_SRC_PORT,
    GTP5G_FLOW_DESCRIPTION_DEST_PORT,

    __GTP5G_FLOW_DESCRIPTION_ATTR_MAX,
};
#define GTP5G_FLOW_DESCRIPTION_ATTR_MAX (__GTP5G_FLOW_DESCRIPTION_ATTR_MAX - 1)

enum gtp5g_far_attrs {
    /* gtp5g_device_attrs in this part */

    GTP5G_FAR_ID = 3,
    GTP5G_FAR_APPLY_ACTION,
    GTP5G_FAR_FORWARDING_PARAMETER,

    /* Not IEs in 3GPP Spec, for other purpose */
    GTP5G_FAR_RELATED_TO_PDR,

    GTP5G_FAR_SEID,
    __GTP5G_FAR_ATTR_MAX,
};
#define GTP5G_FAR_ATTR_MAX (__GTP5G_FAR_ATTR_MAX - 1)

/* Nest in GTP5G_FAR_FORWARDING_PARAMETER */
enum gtp5g_forwarding_parameter_attrs {
    GTP5G_FORWARDING_PARAMETER_OUTER_HEADER_CREATION = 1,
    GTP5G_FORWARDING_PARAMETER_FORWARDING_POLICY,

    __GTP5G_FORWARDING_PARAMETER_ATTR_MAX,
};
#define GTP5G_FORWARDING_PARAMETER_ATTR_MAX (__GTP5G_FORWARDING_PARAMETER_ATTR_MAX - 1)

/* Nest in GTP5G_FORWARDING_PARAMETER_OUTER_HEADER_CREATION */
enum gtp5g_outer_header_creation_attrs {
    GTP5G_OUTER_HEADER_CREATION_DESCRIPTION = 1,
    GTP5G_OUTER_HEADER_CREATION_O_TEID,
    GTP5G_OUTER_HEADER_CREATION_PEER_ADDR_IPV4,
    GTP5G_OUTER_HEADER_CREATION_PORT,

    __GTP5G_OUTER_HEADER_CREATION_ATTR_MAX,
};
#define GTP5G_OUTER_HEADER_CREATION_ATTR_MAX (__GTP5G_OUTER_HEADER_CREATION_ATTR_MAX - 1)

enum {
    GTP5G_SDF_FILTER_ACTION_UNSPEC = 0,

    GTP5G_SDF_FILTER_PERMIT,

    __GTP5G_SDF_FILTER_ACTION_MAX,
};
#define GTP5G_SDF_FILTER_ACTION_MAX (__GTP5G_SDF_FILTER_ACTION_MAX - 1)

enum {
    GTP5G_SDF_FILTER_DIRECTION_UNSPEC = 0,

    GTP5G_SDF_FILTER_IN,
    GTP5G_SDF_FILTER_OUT,

    __GTP5G_SDF_FILTER_DIRECTION_MAX,
};
#define GTP5G_SDF_FILTER_DIRECTION_MAX (__GTP5G_SDF_FILTER_DIRECTION_MAX - 1)

/* ------------------------------------------------------------------
 *                                QER
 * ------------------------------------------------------------------
 * */
enum gtp5g_qer_attrs {
    /* gtp5g_device_attrs in this part */

    GTP5G_QER_ID = 3,
    GTP5G_QER_GATE,
    GTP5G_QER_MBR,
    GTP5G_QER_GBR,
    GTP5G_QER_CORR_ID,
    GTP5G_QER_RQI,
    GTP5G_QER_QFI,
    GTP5G_QER_PPI,
    GTP5G_QER_RCSR,

    /* Not IEs in 3GPP Spec, for other purpose */
    GTP5G_QER_RELATED_TO_PDR,

    GTP5G_QER_SEID,
    __GTP5G_QER_ATTR_MAX,
};
#define GTP5G_QER_ATTR_MAX (__GTP5G_QER_ATTR_MAX - 1)

/* Nest in GTP5G_QER_MBR */
enum gtp5g_qer_mbr_attrs {
    GTP5G_QER_MBR_UL_HIGH32 = 1,
    GTP5G_QER_MBR_UL_LOW8,
    GTP5G_QER_MBR_DL_HIGH32,
    GTP5G_QER_MBR_DL_LOW8,

    __GTP5G_QER_MBR_ATTR_MAX,
};
#define GTP5G_QER_MBR_ATTR_MAX (__GTP5G_QER_MBR_ATTR_MAX - 1)

/* Nest in GTP5G_QER_GBR */
enum gtp5g_qer_gbr_attrs {
    GTP5G_QER_GBR_UL_HIGH32 = 1,
    GTP5G_QER_GBR_UL_LOW8,
    GTP5G_QER_GBR_DL_HIGH32,
    GTP5G_QER_GBR_DL_LOW8,

    __GTP5G_QER_GBR_ATTR_MAX,
};
#define GTP5G_QER_GBR_ATTR_MAX (__GTP5G_QER_GBR_ATTR_MAX - 1)

#endif /* _UAPI_LINUX_GTP_H_ */
