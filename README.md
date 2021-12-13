<div id="top"></div>

[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]



<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/github_username/repo_name">
    <img src="https://cdn1.parksmedia.wdprapps.disney.com/resize/mwImage/1/433/433/75/vision-dam/digital/parks-platform/parks-global-assets/disney-world/0526ZP_1270MS_xak_R2-1x1.jpg?2021-08-05T12:44:38+00:00" alt="Logo" width="500" height="500">
  </a>

<h3 align="center">Traversing DisneyWorld</h3>

  <p align="center">
    For our final project, we chose to work with a dataset which includes data about various rides in Disney parks around the wworld, ranging fron Disneyland California to Disney Paris. We worked over the course of roughly a month to create a tool that calculates the optimal path through the park given a time constraint. We defined the optimal path as the path where the user could go on the most rides in the least amount of time. We also used the wait time for each ride to calculate the path. We used BFS to work with our dataset, and Djikastra's Algorithm as well as Kruskal's Algorithm as our graph algorithm.
    
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li>
      <a href="#installation">Installation</a>
    </li>
    <li><a href="#dataset">Dataset</a></li>
    <li><a href="#building-and-testing">Building and Testing</a></li>
    <li><a href="#features">Features</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/5/5a/Walt_Disney_World_Logo_2018.svg/2560px-Walt_Disney_World_Logo_2018.svg.png" alt="disneyworld" width="640" height="119">

We are using the unofficial API library called wdwJS -- ​​https://github.com/zpocbob/wdwJS. The dataset provides information about various rides in Disney Theme Parks around the world, such as Disney California and Disney Paris. This information includes the individual ride wait times, the schedule for these rides, and which park the ride is located in. We downloaded our data by pulling from the github repository that it was in. We used BFS to work with our dataset because of its queue structure, and are specifically using it to generate the overall path to all the rides. As for our graph algorithms, we chose to use Djikastra's Algorithm, as well as Kruskal's Algorithm. We used Djikastra's Algorithm to calculate the shortest point between two rides. We used Kruskal's Algorithm to generate the maximum amount of rides that a user can ride within their time constraint, by generating a minimum spanning tree. We also used self edges, for which the edge weight is the wait time, whereas for the other edges, the edge weight represents the distance between the two rides.


<p align="right">(<a href="#top">back to top</a>)</p>






<!-- GETTING STARTED -->
## Installation
To get a local version of our project, follow these simple instructions.
Run  ```sh
  git clone https://github-dev.cs.illinois.edu/cs225-fa21/snema2-ag52-knagpu2-shreyap7.git
``` 

<p align="right">(<a href="#top">back to top</a>)</p>


### Dataset
Our dataset is 
<p align="right">(<a href="#top">back to top</a>)</p>


### Building And Testing


<p align="right">(<a href="#top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->
## Features
Our main focus when builing this tool was to make sure that the user had an optimized DisneyWorld experience, which we defined as going on the most rides they could within their time contraint. One key feature of our tool is that  Another key feature of our tool is ()

<p align="right">(<a href="#top">back to top</a>)</p>






<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/github_username/repo_name.svg?style=for-the-badge
[contributors-url]: https://github.com/github_username/repo_name/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/github_username/repo_name.svg?style=for-the-badge
[forks-url]: https://github.com/github_username/repo_name/network/members
[stars-shield]: https://img.shields.io/github/stars/github_username/repo_name.svg?style=for-the-badge
[stars-url]: https://github.com/github_username/repo_name/stargazers
[issues-shield]: https://img.shields.io/github/issues/github_username/repo_name.svg?style=for-the-badge
[issues-url]: https://github.com/github_username/repo_name/issues
[license-shield]: https://img.shields.io/github/license/github_username/repo_name.svg?style=for-the-badge
[license-url]: https://github.com/github_username/repo_name/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/linkedin_username
[product-screenshot]: images/screenshot.png
