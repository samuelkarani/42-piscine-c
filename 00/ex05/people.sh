#!/bin/sh
ldapsearch -h ldap-master.42.us.org -Q "uid=z*" | grep "cn: " | cut -c 5- | sort -r
