# This file is part of pxe. It is subject to the licence terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/pxe/master/COPYRIGHT. No part of pxe, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
# Copyright © 2014-2015 The developers of pxe. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/pxe/master/COPYRIGHT.

set -u
set -f

print_header()
{
	local headerName="$1"
	local headerValue="$2"
	
	printf '%s: %s\n' "$headerName" "$headerValue"
}

print_header_contentType()
{
	print_header "Content-Type" "$1"
}

print_header_status_ok()
{
	print_header "Status" "200 OK"
}

print_header_status_notFound()
{
	print_header "Status" "404 Not Found"
}

print_header_status_methodNotAllowed()
{
	print_header "Status" "405 Method Not Allowed"
}

print_header_status_payloadTooLarge()
{
	print_header "Status" "413 Payload Too Large"
}

print_header_status_unsupportedMediaType()
{
	print_header "Status" "415 Unsupported Media Type"
}

print_header_status_unimplemented()
{
	print_header "Status" "501 Unimplemented"
}

return_empty()
{
	local status="$1"
	
	print_header_contentType "text/plain;charset=utf-8"
	print_header_status_$status
	printf '\n'
	exit 0
}

return_plaintext()
{
	local content="$1"
	
	print_header_contentType "text/plain;charset=utf-8"
	print_header_status_ok
	printf '\n%s' "$content"
	exit 0
}

validate_GATEWAY_INTERFACE()
{
	if [ "$GATEWAY_INTERFACE" != "CGI/1.1" ]; then
		return_empty unimplemented
	fi
}

validate_SERVER_PROTOCOL()
{
	case "$SERVER_PROTOCOL" in
	
		'INCLUDED')
			return_empty unimplemented
		;;
	
		'HTTP/1.0'|'HTTP/1.1')
			:
		;;
	
		*)
			return_empty unimplemented
		;;
	
	esac
}

validate_requestIsGet()
{
	if [ "$REQUEST_METHOD" != 'GET' ]; then
		return_empty methodNotAllowed
	fi
}

validate_thereIsNoQueryString()
{
	if [ -n "$QUERY_STRING" ]; then
		return_empty notFound
	fi
}

validate_thereIsNoContentType()
{
	if [ -n "$_CONTENT_TYPE" ]; then
		return_empty unsupportedMediaType
	fi
}

validate_thereIsNoRequestMessageBody()
{
	if [ $_CONTENT_LENGTH -ne 0 ]; then
		return_empty payloadTooLarge
	fi
}

assign_unsetCgiVariablesToSensibleDefaults()
{
	_PATH_TRANSLATED="${PATH_TRANSLATED:-}"
	_REMOTE_HOST="${REMOTE_HOST:-}"
	_CONTENT_TYPE="${CONTENT_TYPE:-}"
	_CONTENT_LENGTH="${CONTENT_LENGTH:-0}"
}

extract_value_from_query_string()
{
	local key="$1"
	
	local oldIFS="$IFS"
	local IFS="&"
	set -- $QUERY_STRING
	IFS="$oldIFS"
	
	local keyValuePair
	local first=true
	for keyValuePair in "$@"
	do
		if $first; then
			local actualKey='?'"$key"
			first=false
		else
			local actualKey="$key"
		fi
		
		local foundKey
		local value
		IFS='=' read -r foundKey value <<-EOF
			${keyValuePair}
		EOF
		if [ "$foundKey" = "$actualKey" ]; then
			extract_value_from_query_string_RESULT="$value"
			return 0
		fi
	done
	return 1
}

init()
{
	validate_GATEWAY_INTERFACE
	validate_SERVER_PROTOCOL
	assign_unsetCgiVariablesToSensibleDefaults
}
init

