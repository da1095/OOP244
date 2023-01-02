# Computer preparation and Getting Workshop files

## IPC144 Review Session  for OOP244 Students
The review session on IPC144/BTP100 will be held on Sunday Jan 16th, 10 AM to As long as it takes. <br />
This session is open to all the students who need to review the 144 concepts before starting 244 subjects.<br />

PLease use your real name when asked and [Click here to join the Session](https://connect.rna2.blindsidenetworks.com/invite/to?c=nITAIyRBPmb20MmYqBigXExU3DfDWsnc6p4JxVLFbs0&m=1b675d8dc1c952fe3b081555fabab0cc0a9cf35f&t=1642343944512&u=senecacollege)

### Review Recordings
review recording will be posted here.



## Setting up your computers for OOP244

Installation guides for preparing your computer for the subject can be found in this playlist on YouTube:<br />
[Seneca-SDDS "how to" videos for C/C++ Core subjects](https://www.youtube.com/playlist?list=PLxB4x6RkylosAh1of4FnX7-g2fk0MUeyc)<br />
OR:<br />
Go to this url: https://tinyurl.com/244setup 


## Getting Workshop files
(if you have not followed the Installation guides to prepare your computer go to **Using [Download Zip](#using-download-zip)**)<br />

### Using [Git](https://git-scm.com/download/win)
- Open https://github.com/Seneca-244200/OOP-Workshops and click on “Code” Button; this will open “Clone with HTTPS” window.<br />
![The Code Button](images/code.png)
> If the window is titled “Clone with SSH” then click on “Use HTTPS”: <br />
![Use https](images/usehttps.png)
- Copy the https URL by clicking on the button on the right side of the URL:<br />![Copy URL](images/copyurl.png)
- Open File Explorer on your computer and select or create a directory for your workshops.
#### Using [ToroiseGit](https://tortoisegit.org/download/)
- Right click on the selected directory and select “Git Clone":<br /> ![Git Clone](images/gitclone.png)<br />
-This will open the “Git Clone” window with the URL already pasted in the “URL” text box; if not, paste the URL manually:<br /> ![Git Clone Dialog](images/gitcloneDialog.png)<br />
- Click on ok<br />
This will create on your computer a clone (identical directory structure) of the directory on Github.  Once you have cloned the directory, you can open the workshop directory **OOP-Workshops/WS??** and start doing your workshop. Note that you will repeat this process for all workshops and milestones of your project in this subject.
> If your professor makes any changes to the workshop or a new workshop is released, you can right click on the cloned repository directory and select **Tortoise Git/pull** to update and sync your local workshops repositoryy to the one on Github with-out having to download it again. Note that this will only apply the changes made and will not affect any work that you have done on your workshop.
#### Using Command line
- Open the git command line on your computer.
- Change the directory to your workshops directory.
- Issue the following command at the command prompt in your workshops directory: 
``` bash
git clone https://github.com/Seneca-244200/OOP-Workshops.git<ENTER>
```
> The URL for all the workshops are the same throughout the semester. The only thing that changes, is the workshop number.<br/>

This will create a clone (that is an identical directory structure and content to the one Github) of the OOP-Workshops repository on your computer.  Once you have cloned the directory, you can open the subdirectory the workshop and start doing your work. Note that you will repeat this process for all workshops and milestones of your project in this subject.

> If your professor makes any changes to the workshop, you can issue the command
``` bash 
git pull<ENTER>
``` 
>  in the cloned repository directory to update and sync your local workshop to the one on Github without having to download it again. Note that this will only apply the changes made and will not affect any work that you have done on your workshop.

#### Using Download ZIP
- Open https://github.com/Seneca-244200/OOP-Workshops  and click on “Code” button and click on “Download ZIP”.<br />
![Download Zip](images/downloadzip.png)<br />
- This will download a zipped file copy of the workshop repository from Github to your computer. You can extract this file to where you want to do your workshop. <br />
> Note that, if your professor makes any changes to the workshop, to get them you have to separately download another copy of the workshop and manually apply the changes to your working directory to **make sure nothing of your work is overwritten by mistake**.

# Improtant Notes
- Install [GlobalProtect](https://inside.senecacollege.ca/its/services/vpn/senecavpn.html) on your computer to have access to internal services of Seneca and the Matrix Linux cluster.
- When transferring program files to Matrix using an SFTP or SSH client, make sure your transfer mode is always set to **TEXT**
