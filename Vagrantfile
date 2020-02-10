Vagrant.configure("2") do |config|
  config.vm.box = "ubuntu/xenial64"

  config.vm.provision "shell", inline: <<-SHELL
    apt-get update
    apt-get upgrade
    apt-get install -y make gcc g++ cmake
  SHELL

  config.vm.provider "virtualbox" do |vbox|
    vbox.customize ["modifyvm", :id, "--uartmode1", "disconnected"] 
    vbox.memory = 4096
    vbox.cpus = 4
    vbox.name = "Kiki_VM"
    vbox.gui = false
  end

  config.vm.provision "shell", inline: <<-SHELL
    cp -r /vagrant/comp-2018-operating-system /home/vagrant/kiki
    cd /home/vagrant/kiki
    chmod +x install.sh && ./install.sh
    rm -r kernel_module
    rm -r man
    rm install.sh
    rm -r c_api/solution_src/kiki_api.c
    cp /vagrant/starter/kiki_api.c c_api/solution_src/kiki_api.c
    mkdir ~/kiki/kernel_module/src
    cp /vagrant/comp-2018-operating-system/kernel_module/src/correction_stats_struct.* ~/kiki/kernel_module/src/
    chown -R vagrant kiki
    chgrp -R vagrant kiki
  SHELL

  config.vm.provision "shell", inline: <<-SHELL
    sudo apt-get clean
    cat /dev/null > ~/.bash_history && history -c
  SHELL

  # Create a forwarded port mapping which allows access to a specific port
  # within the machine from a port on the host machine. In the example below,
  # accessing "localhost:8080" will access port 80 on the guest machine.
  # NOTE: This will enable public access to the opened port
  # config.vm.network "forwarded_port", guest: 80, host: 8080

  # Create a forwarded port mapping which allows access to a specific port
  # within the machine from a port on the host machine and only allow access
  # via 127.0.0.1 to disable public access
  # config.vm.network "forwarded_port", guest: 80, host: 8080, host_ip: "127.0.0.1"

  # Create a private network, which allows host-only access to the machine
  # using a specific IP.
  # config.vm.network "private_network", ip: "192.168.33.10"

  # Share an additional folder to the guest VM. The first argument is
  # the path on the host to the actual folder. The second argument is
  # the path on the guest to mount the folder. And the optional third
  # argument is a set of non-required options.

  # Enable provisioning with a shell script. Additional provisioners such as
  # Puppet, Chef, Ansible, Salt, and Docker are also available. Please see the
  # documentation for more information about their specific syntax and use.
  # config.vm.provision "shell", inline: <<-SHELL
  #   apt-get update
  #   apt-get install -y apache2
  # SHELL
end
