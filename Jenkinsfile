pipeline {

    environment {
	major=0
	minor=1
	patch="${env.BUILD_ID}"
        name="${env.JOB_NAME}"
        version="$major.$minor.$patch"
    	exec_name="sbet-decoder-$version"

        publishDir="/var/www/html/$name/$version"
        lastPublishDir="/var/www/html/$name/last"
	binMasterPublishDir="$publishDir/bin/debian9/bin"
	binWinx64Dir="bin/windows-x64/bin"
	binWinx64PublishDir="$publishDir/$binWinx64Dir"
    }

    agent none
    stages {
        stage('TEST MASTER'){
            agent { label 'master'}
            steps {
              sh "make test"
            }
        }

        stage('DOCUMENTATION'){
          agent { label 'master'}
          steps {
              sh "make doc"
            }
        }
        stage('BUILD MASTER'){
            agent { label 'master'}
            steps {
              	sh 'make'
                sh 'mkdir -p $binMasterPublishDir'
        	sh 'cp -r build/bin/sbet-decoder $binMasterPublishDir/$exec_name'
            }
        }
       stage('BUILD WINDOWS AND TEST'){
            agent {label 'windows10-x64-2'}
	    steps {
		//compile
		bat 'if not exist build\\bin mkdir build\\bin'
		bat 'call "%windows10_x64_BUILD_TOOLS_ROOT%\\VC\\Auxiliary\\Build\\vcvarsall.bat" x64 && cd build\\bin &&cl ..\\..\\src\\main.cpp /Fesbet-decoder.exe'
		bat 'cd ..\\..\\'
                bat 'if not exist build\\bin\\windows-x64 mkdir build\\bin\\windows-x64'
                bat 'copy /b build\\bin\\*.exe build\\bin\\windows-x64'
                bat 'copy build\\bin\\sbet-decoder.exe  build\\bin\\windows-x64\\%exec_name%.exe'

                archiveArtifacts('build\\bin\\sbet-decoder.exe') // pour le test (path codé en dur dans le test ...)
                archiveArtifacts('build\\bin\\windows-x64\\*.exe')  // pour la publication

                bat 'if not exist build\\test mkdir build\\test'
		bat 'g++ -Wall test\\CatchMain.cpp -c -o build\\test\\CatchMain.o'
	 	bat 'g++ -Wall build\\test\\CatchMain.o test\\TemplateTest.cpp -o build\\test\\TemplateTest && build\\test\\TemplateTest -r compact'
                archiveArtifacts('build/test/TemplateTest.exe')

		bat 'if not exist build\\test mkdir build\\test'
		bat 'copy /b test\\data\\* build\\test'
		bat 'if not exist build\\test\\reports rd /s /q build\\test\\reports'
		bat 'mkdir build\\test\\reports'		
		bat 'cd build\\test && TemplateTest.exe -r junit -o reports\\TemplateTest-windows10-x64.xml'

	  }
	  post {
	     always {
		junit 'build\\test\\reports\\TemplateTest-windows10-x64.xml'
	  }
		
	}
    }
    
    stage('SAVE WINDOWS EXE on SERVER'){
         agent { label 'master' }
            steps {
                sh 'mkdir -p $binWinx64PublishDir'
                sh 'cp  /var/lib/jenkins/jobs/$name/builds/$patch/archive/build/bin/windows-x64/bin/$exec_name.exe  $binWinx64PublishDir/.'
                sh 'cp  /var/lib/jenkins/jobs/$name/builds/$patch/archive/build/test/bin/test-sbet-decoder.exe  $binWinx64PublishDir/.'
            }
        }
  }
}
