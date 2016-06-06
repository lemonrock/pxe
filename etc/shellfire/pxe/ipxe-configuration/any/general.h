// This file is part of pxe. It is subject to the licence terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/pxe/master/COPYRIGHT. No part of pxe, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2014-2015 The developers of pxe. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/pxe/master/COPYRIGHT.


// general.h overrides

// Enable IPv6 support
#define NET_PROTO_IPV6

#undef DOWNLOAD_PROTO_HTTP
#undef DOWNLOAD_PROTO_TFTP
#define DOWNLOAD_PROTO_HTTPS

#undef NET_PROTO_STP
#undef NET_PROTO_LACP

#undef HTTP_AUTH_BASIC
#undef HTTP_AUTH_DIGEST

#undef CRYPTO_80211_WEP
#undef CRYPTO_80211_WPA
#undef CRYPTO_80211_WPA2
	
// Disable script support for Inifiniband, Wireleess, Sanboot, Fibre Channel
#undef IBMGMT_CMD
#undef IWMGMT_CMD
#undef SANBOOT_CMD
#undef FCMGMT_CMD

// Enable script support for hashes, imgtrust and reboot
#define DIGEST_CMD
#define IMAGE_TRUST_CMD
#define REBOOT_CMD

// Disable Infiniband VNICs
#undef VNIC_IPOIB

// defaults/pcbios.h overrides
#undef SANBOOT_PROTO_ISCSI
#undef SANBOOT_PROTO_AOE
#undef SANBOOT_PROTO_IB_SRP
#undef SANBOOT_PROTO_FCP
#undef SANBOOT_PROTO_HTTP
#undef IMAGE_ELF
#undef IMAGE_MULTIBOOT
#undef IMAGE_PXE

// defaults/efi.h overrides
#undef UACCESS_EFI
#undef IOMAP_VIRT
#undef PCIAPI_EFI
#undef CONSOLE_EFI
#undef TIMER_EFI
#undef UMALLOC_EFI
#undef SMBIOS_EFI
#undef SANBOOT_NULL
#undef BOFM_EFI
#undef ENTROPY_EFI
#undef TIME_EFI
#undef REBOOT_EFI
#undef DOWNLOAD_PROTO_FILE
#undef IMAGE_EFI
#undef USB_EFI

// defaults/linux.h overrides
#undef CONSOLE_LINUX
#undef TIMER_LINUX
#undef UACCESS_LINUX
#undef UMALLOC_LINUX
#undef NAP_LINUX
#undef SMBIOS_LINUX
#undef SANBOOT_NULL
#undef ENTROPY_LINUX
#undef TIME_LINUX
#undef REBOOT_NULL
#undef PCIAPI_LINUX
#undef DRIVERS_LINUX
#undef IMAGE_SCRIPT

#undef ROM_BANNER_TIMEOUT
#define ROM_BANNER_TIMEOUT 0
#undef BANNER_TIMEOUT
#define BANNER_TIMEOUT 30