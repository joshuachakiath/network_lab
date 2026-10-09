# network_lab

Exp 4
  sudo resolvectl flush-caches
  ipconfig /flushdns

Exp 6,8,9
  run files in two seperate terminal.
  run commands: gcc filename, ./a.out

Exp 11
  Purpose	Command
  Enter privileged mode	            enable
  Enter configuration mode	        configure terminal
  Exit configuration mode	          end
  Display router information	      show version
  Display running configuration	    show running-config
  Display startup configuration	    show startup-config
  Display routing protocols	        show ip protocols
  Display routing table	            show ip route
  Display command history	          show history
  Display router clock	            show clock
  Display hosts	                    show hosts
  Detailed interface information	  show interfaces
  Brief interface information	      show ip interface brief
  Determine DTE/DCE	                show controllers serial 0/0/0
  Select an interface	              interface ...
  Assign IP address	                ip address IP MASK
  Enable interface	                no shutdown
  Disable interface	                shutdown
  Configure DCE clock	              clock rate 64000
  Save configuration	              copy running-config startup-config

Exp 12-14
  show ip ospf neighbor // to check ospf connection. FULL means working
  for rip v2: go to router-> cli -> 
  commands: enable
            configure terminal
            router rip
            version 2
            end
            
