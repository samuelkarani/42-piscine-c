ldapsearch -h ldap-master.42.us.org -Q "sn=*bon*" | grep "sn: " | wc -l
