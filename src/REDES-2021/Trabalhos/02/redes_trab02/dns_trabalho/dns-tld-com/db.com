$TTL 60000
@	IN	SOA	dns.com.	admin.dns.com. (
	1234
	30
	15
	60000
	0
)
@		IN	NS	dns.com.
dns.com.	IN	A	10.0.5.10

google.com.	IN	NS	dns.google.com.
dns.google.com.	IN	A	10.0.4.10
