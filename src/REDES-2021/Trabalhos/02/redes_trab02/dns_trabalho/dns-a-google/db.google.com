$TTL 60000
@	IN	SOA	dns.google.com.	admin.dns.google.com. (
	1234
	30
	15
	60000
	0
	)
@		IN	NS	dns.google.com.
dns.google.com.	IN	A	10.0.4.10
web		IN	A	10.0.4.11
www		IN	CNAME	web
