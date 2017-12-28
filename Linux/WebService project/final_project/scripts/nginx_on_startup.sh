#!/bin/bash
sudo nginx -c /root/final_project/nginx.conf
sudo spawn-fcgi -a 127.0.0.1 -p 8000  -d /etc/nginx/cgi-bin/bin  /etc/nginx/cgi-bin/bin/tic_tac_toe
