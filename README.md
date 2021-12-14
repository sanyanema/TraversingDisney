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
      <a href="#commands-to-run-the-program">Commands To Run The Program</a>
    </li>
    <li><a href="#dataset">Dataset</a></li>
    <li><a href="#test-suite-and-testing">Test Suite and Testing</a></li>
    <li><a href="#features">Features</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/5/5a/Walt_Disney_World_Logo_2018.svg/2560px-Walt_Disney_World_Logo_2018.svg.png" alt="disneyworld" width="640" height="119">

We are using the unofficial API library called wdwJS -- ​​https://github.com/cubehouse/themeparks. The dataset provides information about various rides in Disney Theme Parks around the world, such as Disney California and Disney Paris. This information includes the individual ride wait times, the schedule for these rides, and which park the ride is located in. We downloaded our data by pulling from the github repository that it was in. We used BFS to work with our dataset because of its queue structure, and are specifically using it to generate the overall path to all the rides. As for our graph algorithms, we chose to use Djikastra's Algorithm, as well as Kruskal's Algorithm. We used Djikastra's Algorithm to calculate the shortest point between two rides. 

Given a starting ride, Dijkstra’s will return the shortest path for each ride from that ride. This means that if we start at Ride 1, and want to go to Ride 3, there might be multiple paths. You could go from Ride 1 to Ride 5 to Ride 3, or Ride 1 to Ride 4 to Ride 3, and one of these will be the shortest. This can help the rider understand how to get to a certain ride the quickest way, if they only care about that specific ride.

Kruskal’s also generates the shortest path given a specific starting node, however it attempts to provide the rider with the greatest number of rides while maintaining the shortest path. The use case for this is to generate a path that not only takes the least amount of time/distance, but also allows the rider to visit most of Disneyworld. 


<p align="right">(<a href="#top">back to top</a>)</p>






<!-- GETTING STARTED -->
## Commands To Run The Program
To get a local version of our project, follow these simple instructions. Run  ```git clone https://github-dev.cs.illinois.edu/cs225-fa21/snema2-ag52-knagpu2-shreyap7.git``` 
To make the prject after you have cloned it, run
```
  make
  ./project
``` 
In the 
```main.cpp```, we pass in the dataset as a filename and our output location is 3 ```.txt``` files, one for each of the algorithms.

<p align="right">(<a href="#top">back to top</a>)</p>


### Dataset
We are using the unofficial API library called wdwJS -- ​​https://github.com/zpocbob/wdwJS. The dataset provides information about various rides in Disney Theme Parks around the world, such as Disney California and Disney Paris. This information includes the individual ride wait times, the schedule for these rides, and which park the ride is located in. We are hoping to solve the specific problem of amusement park goers having to wait in long lines. By tracking wait times and the distance away a person is from a certain ride we can allow them to figure out what theme park they should go to at a certain time. We are hoping to produce a search tool, where the input is the current location at the park, and the output will be a list of suggested rides ranked using shortest wait time, distance from rides, and the ability to optimize the future ride order. To us, a successful project looks like a working search tool that can help users optimize their amusement park experience. Based on the user’s location in the park, we want to be able to provide them with their ideal and most optimized experience based on their location and wait time. 

<p align="right">(<a href="#top">back to top</a>)</p>


### Test Suite and Testing
To test the code, run the following command
```sh
  make test
  ./test
``` 
Our test suite includes tests for each algorithm we used, as well as the graph, edge, and node classes. We tested the addNode(), addEdges(), getNode(), and getCSV() functions. We also tested our destructors as well as our Lattitude and Longitude distance functions.
<p align="right">(<a href="#top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->
## Features
Our main focus when builing this tool was to make sure that the user had an optimized DisneyWorld experience, which we defined as going on the most rides they could within their time contraint. The most important key feature of our tool is that we find the most optimized path around the Disneyworld park.

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