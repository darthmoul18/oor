lig 192.0.2.1
lig 192.0.2.2
tshark -n -i eth1 -i eth2 -Y "icmp || lisp || lisp-data || vxlan"
ping 192.0.2.1
ping 192.0.2.2
sudo oor -D
tail -f /var/log/oor.log
