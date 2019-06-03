#!/bin/sh
ldapsearch -h ldap-master.42.us.org -Q "uid=smbaabu" | grep "dn: " | cut -c 5-

