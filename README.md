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
    <img src="https://cdn1.parksmedia.wdprapps.disney.com/resize/mwImage/1/433/433/75/vision-dam/digital/parks-platform/parks-global-assets/disney-world/0526ZP_1270MS_xak_R2-1x1.jpg?2021-08-05T12:44:38+00:00" alt="Logo" width="450" height="450">
  </a>

<h3 align="center">Traversing DisneyWorld</h3>

  <p align="center">
    We are using the unofficial API library called wdwJS -- ​​https://github.com/zpocbob/wdwJS. The dataset provides information about various rides in Disney Theme Parks around the world, such as Disney California and Disney Paris. This information includes the individual ride wait times, the schedule for these rides, and which park the ride is located in. We downloaded our data by pulling from the github repository that it was in. We used BFS to work with our dataset because of its queue structure, and are specifically using it to calculate the shortest distance between where the user is and where they would like to be. As for our graph algorithms, we chose to use Djikastra's Algorithm, as well as Kruskal's Algorithm. We used Djikastra's Algorithm to calculate the shortest point between two locations. We used Kruskal's Algorithm to generate the maximum amount of rides that a user can ride within their time contraint, and generate a landmark path for them.
    <br />
    <a href="https://github.com/github_username/repo_name"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/github_username/repo_name">View Demo</a>
    ·
    <a href="https://github.com/github_username/repo_name/issues">Report Bug</a>
    ·
    <a href="https://github.com/github_username/repo_name/issues">Request Feature</a>
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
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

<img src="https://static.wikia.nocookie.net/logopedia/images/3/3b/Walt_Disney_World_2005.svg/revision/latest/scale-to-width-down/250?cb=20190327161304" alt="disneyworld" width="250" height="137">
<!-- [![h][https://static.wikia.nocookie.net/logopedia/images/3/3b/Walt_Disney_World_2005.svg/revision/latest/scale-to-width-down/250?cb=20190327161304](https://static.wikia.nocookie.net/logopedia/images/3/3b/Walt_Disney_World_2005.svg/revision/latest/scale-to-width-down/250?cb=20190327161304) -->

We are using the unofficial API library called wdwJS -- ​​https://github.com/zpocbob/wdwJS. The dataset provides information about various rides in Disney Theme Parks around the world, such as Disney California and Disney Paris. This information includes the individual ride wait times, the schedule for these rides, and which park the ride is located in. We downloaded our data by pulling from the github repository that it was in. We used BFS to work with our dataset because of its queue structure, and are specifically using it to calculate the shortest distance between where the user is and where they would like to be. As for our graph algorithms, we chose to use Djikastra's Algorithm, as well as Kruskal's Algorithm. We used Djikastra's Algorithm to calculate the shortest point between two locations. We used Kruskal's Algorithm to generate the maximum amount of rides that a user can ride within their time contraint, and generate a landmark path for them.


<p align="right">(<a href="#top">back to top</a>)</p>



### Built With

* [Next.js](https://nextjs.org/
* [C++](https://laravel.com)

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- GETTING STARTED -->
## Installation

This is an example of how you may give instructions on setting up your project locally.
To get a local copy up and running follow these simple example steps.

### Dataset

This is an example of how to list things you need to use the software and how to install them.
* npm
  ```sh
  npm install npm@latest -g
  ```

### Building And Testing

1. Get a free API Key at [https://example.com](https://example.com)
2. Clone the repo
   ```sh
   git clone https://github.com/github_username/repo_name.git
   ```
3. Install NPM packages
   ```sh
   npm install
   ```
4. Enter your API in `config.js`
   ```js
   const API_KEY = 'ENTER YOUR API';
   ```

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->
## Features

Use this space to show useful examples of how a project can be used. Additional screenshots, code examples and demos work well in this space. You may also link to more resources.

_For more examples, please refer to the [Documentation](https://example.com)_

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
